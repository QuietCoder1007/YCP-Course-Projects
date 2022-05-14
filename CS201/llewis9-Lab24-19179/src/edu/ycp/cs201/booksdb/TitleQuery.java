package edu.ycp.cs201.booksdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;

import edu.ycp.cs201.sqldemo.DBUtil;

public class TitleQuery {
	public static void main(String[] args) throws Exception {
		// load Derby JDBC driver
		try {
			Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
		} catch (Exception e) {
			System.err.println("Could not load Derby JDBC driver");
			System.err.println(e.getMessage());
			System.exit(1);
		}

		Connection conn = null;
		PreparedStatement stmt = null;
		ResultSet resultSet = null;

		// connect to the database
		conn = DriverManager.getConnection("jdbc:derby:test.db;create=true");

		@SuppressWarnings("resource")
		Scanner keyboard = new Scanner(System.in);

		try {
			conn.setAutoCommit(true);
			
			// prompt user for title to search for
			System.out.print("Title to find: ");
			String title = keyboard.nextLine();

			// a canned query to find book information (including author name) from title
			stmt = conn.prepareStatement(
					"select authors.author_lastname, authors.author_firstname, books.title, books.isbn "
					+ "  from authors, books "
					+ "  where authors.author_id = books.author_id "
					+ "        and books.title = ?"
			);

			// substitute the title entered by the user for the placeholder in the query
			stmt.setString(1, title);

			// execute the query
			resultSet = stmt.executeQuery();

			// get the precise schema of the tuples returned as the result of the query
			ResultSetMetaData resultSchema = stmt.getMetaData();

			// iterate through the returned tuples, printing each one
			while (resultSet.next()) {
				for (int i = 1; i <= resultSchema.getColumnCount(); i++) {
					Object obj = resultSet.getObject(i);
					if (i > 1) {
						System.out.print(",");
					}
					System.out.print(obj.toString());
				}
				System.out.println();
			}
		} finally {
			// close result set, statement, connection
			DBUtil.closeQuietly(resultSet);
			DBUtil.closeQuietly(stmt);
			DBUtil.closeQuietly(conn);
		}
	}
}
