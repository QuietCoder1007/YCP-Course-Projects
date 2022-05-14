package edu.ycp.cs201.booksdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;

import edu.ycp.cs201.sqldemo.DBUtil;

public class FindAuthorQuery {
	@SuppressWarnings("resource")
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
		PreparedStatement stmt2 = null;
		ResultSet resultSet = null;
		ResultSetMetaData resultSchema = null;
		ResultSetMetaData resultSchema2 = null;

		// connect to the database
		conn = DriverManager.getConnection("jdbc:derby:test.db;create=true");

		Scanner keyboard = new Scanner(System.in);

		try {
			conn.setAutoCommit(true);
			
			// prompt user for last name to search for
			System.out.print("Author's last name: ");
			String lastName = keyboard.nextLine();
			
			// prompt user for first name to search for
			System.out.print("Author's first name: ");
			String firstName = keyboard.nextLine();
			
			// a canned query to insert new book information for an author from title
			stmt = conn.prepareStatement(
				"Select authors.author_id" 
					+ "	from authors"
					+ "	where authors.author_lastname = ? and"
					+ "	authors.author_firstname = ?"
					
			);
			// substitute the title entered by the user for the placeholder in the query
			stmt.setString(1, lastName);
			stmt.setString(2, firstName);
			
			// execute the query
			resultSet = stmt.executeQuery();

			// get the precise schema of the tuples returned as the result of the query
			resultSchema = stmt.getMetaData();

			// iterate through the returned tuples, printing each one
			String author_id = null;
			int a_id = 0;
			while (resultSet.next()) {
				for (int i = 1; i <= resultSchema.getColumnCount(); i++) {
					Object stuff = resultSet.getObject(i);
					author_id = stuff.toString();
				}
			}
			
			a_id = Integer.parseInt(author_id);
			
			stmt2 = conn.prepareStatement(
				"insert into books(author_id, title, isbn)"
					+"	values(?, ?, ?)"
			);
			
			// prompt user for title to search for
			System.out.print("Title to find: ");
			String title = keyboard.nextLine();

			// prompt user for book isbn to search for
			System.out.print("Book's isbn: ");
			String isbn = keyboard.nextLine();
			
			// substitute the title entered by the user for the placeholder in the query
			System.out.println(a_id);
			
			
			stmt2.setInt(1, a_id);
			stmt2.setString(2, title);
			stmt2.setString(3, isbn);

			// execute the query
			stmt2.executeUpdate();

			// get the precise schema of the tuples returned as the result of the query
			resultSchema2 = stmt2.getMetaData();
		} finally {
			// close result set, statement, connection
			DBUtil.closeQuietly(resultSet);
			DBUtil.closeQuietly(stmt);
			DBUtil.closeQuietly(stmt2);
			DBUtil.closeQuietly(conn);
		}
	}
}
