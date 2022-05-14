package edu.ycp.cs320.booksdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;

import edu.ycp.cs320.sqldemo.DBUtil;
import edu.ycp.cs320.booksdb.TitleQuery;

public class InsertNewBookWithAuthor {
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
		PreparedStatement stmt3 = null;
		ResultSetMetaData resultSchema = null;
		
		ResultSet resultSet = null;
		
		String lastName = null;
		String firstName = null;
		String id = null;
		String choice = "";

		// connect to the database
		conn = DriverManager.getConnection("jdbc:derby:test.db;create=true");

		Scanner keyboard = new Scanner(System.in);

		try {
			conn.setAutoCommit(true);
			while(true) {
				System.out.print("Insert Book to new user or old user? ");
				choice = keyboard.nextLine();
				choice = choice.toLowerCase();
				if (choice.equals("new") || choice.equals("old")){
					break;
				}
				else {
					System.out.println("Please answer NEW or OLD!");
				}
			}
			if(choice.equals("new")) {
				System.out.print("Author's last name: ");
				lastName = keyboard.nextLine();
				
				// prompt user for first name to search for
				System.out.print("Author's first name: ");
				firstName = keyboard.nextLine();
				
				stmt = conn.prepareStatement(
					"insert into authors(authors.lastname, authors.firstname)"
					+"	values(?, ?)"
				);

				stmt.setString(1, lastName);
				stmt.setString(2, firstName);
			}
			else if(choice.equals("old")) {
			// prompt user for last name to search for
				System.out.print("Author's last name: ");
				lastName = keyboard.nextLine();
				
				// prompt user for first name to search for
				System.out.print("Author's first name: ");
				firstName = keyboard.nextLine();
				
				stmt = conn.prepareStatement(
					"select authors.author_id "
					+ " from authors "
					+ " where authors.lastname=?  and authors.firstname=?"
				);

				stmt.setString(1, lastName);
				stmt.setString(2, firstName);
			}
			// execute the query
			stmt.executeUpdate();
			
			// a canned query to insert new book information for an author from title
			stmt2 = conn.prepareStatement(
				"Select authors.author_id" 
					+ "	from authors"
					+ "	where authors.lastname = ? and"
					+ "	authors.firstname = ?"
			);

			// substitute the author_lastname and author_firstname entered 
			// by the user for the placeholder in the query
			stmt2.setString(1, lastName);
			stmt2.setString(2, firstName);
			
			// execute the query
			resultSet = stmt2.executeQuery();

			// get the precise schema of the tuples returned as the result of the query
			resultSchema = stmt2.getMetaData();

			// iterate through the returned tuples, printing each one
			int author_id = 0;
			while (resultSet.next()) {
				for (int i = 1; i <= resultSchema.getColumnCount(); i++) {
					Object stuff = resultSet.getObject(i);
					id = stuff.toString();
				}
			}
			
			author_id = Integer.parseInt(id);
			
			System.out.print("Title to insert: ");
			String title = keyboard.nextLine();

			// prompt user for book isbn to insert or search for
			System.out.print("Book isbn to insert: ");
			String isbn = keyboard.nextLine();
			
			// prompt user for book  to search for
			System.out.print("Book isbn to insert: ");
			int published = keyboard.nextInt();
			
			stmt3 = conn.prepareStatement(
				"insert into books(author_id, title, isbn, published)"
					+"	values(?, ?, ?, ?)"
			);
			
			// substitute the title entered by the user for the placeholder in the query
			System.out.println(author_id);
			
			
			stmt3.setInt(1, author_id);
			stmt3.setString(2, title);
			stmt3.setString(3, isbn);
			stmt3.setInt(4, published);

			// execute the query
			stmt3.executeUpdate();

			// get the precise schema of the tuples returned as the result of the query
			resultSchema = stmt3.getMetaData();

			} finally {
			// close result set, statement, connection
			DBUtil.closeQuietly(resultSet);
			DBUtil.closeQuietly(stmt);
			DBUtil.closeQuietly(stmt2);
			DBUtil.closeQuietly(stmt3);
			DBUtil.closeQuietly(conn);
		}
	}
}