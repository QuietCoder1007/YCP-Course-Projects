package edu.ycp.cs201.booksdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;

import edu.ycp.cs201.sqldemo.DBUtil;

public class AllTitlesQuery {
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
			String lastName = keyboard.nextLine();
			
			if(Character.isLowerCase(lastName.charAt(0))) {
				char oldChar = lastName.charAt(0);
				Character.toUpperCase(oldChar);
				lastName.replace(lastName.charAt(0), oldChar);
			}
			
			// a canned query to find book title (including author name) from author's last name
			stmt = conn.prepareStatement(
					"select books.title"
					+ "  from authors, books "
					+ "  where authors.author_id = books.author_id "
					+ "        and authors.author_lastname = ?"
			);

			// substitute the title entered by the user for the placeholder in the query
			stmt.setString(1,lastName);
			

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
