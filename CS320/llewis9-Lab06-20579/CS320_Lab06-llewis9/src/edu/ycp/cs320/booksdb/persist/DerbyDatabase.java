package edu.ycp.cs320.booksdb.persist;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import edu.ycp.cs320.booksdb.model.Author;
import edu.ycp.cs320.booksdb.model.Book;
import edu.ycp.cs320.booksdb.model.Pair;

public class DerbyDatabase implements IDatabase {
	static {
		try {
			Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
		} catch (Exception e) {
			throw new IllegalStateException("Could not load Derby driver");
		}
	}
	
	private interface Transaction<ResultType> {
		public ResultType execute(Connection conn) throws SQLException;
	}

	private static final int MAX_ATTEMPTS = 10;

	@Override
	public List<Pair<Author, Book>> findAuthorAndBookByTitle(final String title) {
		return executeTransaction(new Transaction<List<Pair<Author,Book>>>() {
			@Override
			public List<Pair<Author, Book>> execute(Connection conn) throws SQLException {
				PreparedStatement stmt = null;
				ResultSet resultSet = null;
				
				try {
					// retreive all attributes from both Books and Authors tables
					stmt = conn.prepareStatement(
							"select authors.*, books.* " +
							"  from authors, books " +
							" where authors.author_id = books.author_id " +
							"   and books.title = ?"
					);
					stmt.setString(1, title);
					
					List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
					
					resultSet = stmt.executeQuery();
					
					// for testing that a result was returned
					Boolean found = false;
					
					while (resultSet.next()) {
						found = true;
						
						// create new Author object
						// retrieve attributes from resultSet starting with index 1
						Author author = new Author();
						loadAuthor(author, resultSet, 1);
						
						// create new Book object
						// retrieve attributes from resultSet starting at index 4
						Book book = new Book();
						loadBook(book, resultSet, 4);
						
						result.add(new Pair<Author, Book>(author, book));
					}
					
					// check if the title was found
					if (!found) {
						System.out.println("<" + title + "> was not found in the books table");
					}
					
					return result;
				} finally {
					DBUtil.closeQuietly(resultSet);
					DBUtil.closeQuietly(stmt);
				}
			}
		});
	}
	
	public List<Pair<Author, Book>> findAuthorAndBookByAuthorLastName(final String lastname) {
		return executeTransaction(new Transaction<List<Pair<Author,Book>>>() {
			@Override
			public List<Pair<Author, Book>> execute(Connection conn) throws SQLException {
				PreparedStatement stmt = null;
				ResultSet resultSet = null;
				
				try {
					// retrieve all attributes from both Books and Authors tables
					stmt = conn.prepareStatement(
							"select authors.*, books.* "
							+ "  from authors, books "
							+ "  where authors.author_id = books.author_id "
							+ "        and authors.lastname = ? "
							+ " order by title ASC "
					);
					stmt.setString(1, lastname);
					
					List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
					
					resultSet = stmt.executeQuery();
					
					// for testing that a result was returned
					Boolean found = false;
					
					while (resultSet.next()) {
						found = true;
						
						// create new Author object
						// retrieve attributes from resultSet starting with index 1
						Author author = new Author();
						loadAuthor(author, resultSet, 1);
						
						// create new Book object
						// retrieve attributes from resultSet starting at index 4
						Book book = new Book();
						loadBook(book, resultSet, 4);
						
						result.add(new Pair<Author, Book>(author, book));
					}
					
					// check if the lastname was found
					if (!found) {
						System.out.println("<" + lastname + "> was not found in the authors table");
					}
					
					return result;
				} finally {
					DBUtil.closeQuietly(resultSet);
					DBUtil.closeQuietly(stmt);
				}
			}
		});
	}
	
	public List<Pair<Author, Book>> insertNewBookWithAuthor(final String firstname, final String lastname, final String title, final String isbn, final Integer published){ 
		return executeTransaction(new Transaction<List<Pair<Author,Book>>>() {
			public List<Pair<Author, Book>> execute(Connection conn) throws SQLException {
				PreparedStatement stmt = null;
				PreparedStatement stmt2 = null;
				PreparedStatement stmt3 = null;
				PreparedStatement stmt4 = null;
				ResultSetMetaData resultSchema = null;
				ResultSet resultSet = null;
		
				try {
					conn.setAutoCommit(true);
					stmt = conn.prepareStatement(
							"select authors.author_id "
							+ " from authors "
							+ " where authors.lastname=?  and authors.firstname=?"
						);	
		
						stmt.setString(1, lastname);
						stmt.setString(2, firstname);
						
						
					if( stmt.executeQuery() == null) {
						stmt2 = conn.prepareStatement(
								"insert into authors(authors.lastname, authors.firstname) "
								+"	values(?, ?)"
						);
						stmt2.setString(1, lastname);
						stmt2.setString(2, firstname);

						// execute the query
						stmt2.executeUpdate();
					}
					
					List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
					
					// a canned query to insert new book information for an author from title
					stmt3 = conn.prepareStatement(
						"Select authors.author_id" 
							+ "	from authors"
							+ "	where authors.lastname = ? and"
							+ "	authors.firstname = ?"
					);
		
					// substitute the author_lastname and author_firstname entered 
					// by the user for the placeholder in the query
					stmt3.setString(1, lastname);
					stmt3.setString(2, firstname);
					
					// execute the query
					resultSet = stmt3.executeQuery();
		
					// get the precise schema of the tuples returned as the result of the query
					resultSchema = stmt3.getMetaData();
		
					// iterate through the returned tuples, printing each one
					int author_id = 0;
					String id = null;
					while (resultSet.next()) {
						for (int i = 1; i <= resultSchema.getColumnCount(); i++) {
							Object stuff = resultSet.getObject(i);
							id = stuff.toString();
						}
					}
					
					author_id = Integer.parseInt(id);
					
					stmt4 = conn.prepareStatement(
						"insert into books(author_id, title, isbn, published)"
							+"	values(?, ?, ?, ?)"
					);
					
					// substitute the title entered by the user for the placeholder in the query
					System.out.println(author_id);
					
					
					stmt4.setInt(1, author_id);
					stmt4.setString(2, title);
					stmt4.setString(3, isbn);
					stmt4.setInt(4, published);
		
					// execute the query
					stmt4.executeUpdate();
					
					return result;
					
					} finally {
					// close result set, statement, connection
					DBUtil.closeQuietly(resultSet);
					DBUtil.closeQuietly(stmt);
					DBUtil.closeQuietly(stmt2);
					DBUtil.closeQuietly(stmt3);
					DBUtil.closeQuietly(stmt4);
				}
			}
		});
	}
	
	public<ResultType> ResultType executeTransaction(Transaction<ResultType> txn) {
		try {
			return doExecuteTransaction(txn);
		} catch (SQLException e) {
			throw new PersistenceException("Transaction failed", e);
		}
	}
	
	public<ResultType> ResultType doExecuteTransaction(Transaction<ResultType> txn) throws SQLException {
		Connection conn = connect();
		
		try {
			int numAttempts = 0;
			boolean success = false;
			ResultType result = null;
			
			while (!success && numAttempts < MAX_ATTEMPTS) {
				try {
					result = txn.execute(conn);
					conn.commit();
					success = true;
				} catch (SQLException e) {
					if (e.getSQLState() != null && e.getSQLState().equals("41000")) {
						// Deadlock: retry (unless max retry count has been reached)
						numAttempts++;
					} else {
						// Some other kind of SQLException
						throw e;
					}
				}
			}
			
			if (!success) {
				throw new SQLException("Transaction failed (too many retries)");
			}
			
			// Success!
			return result;
		} finally {
			DBUtil.closeQuietly(conn);
		}
	}

	private Connection connect() throws SQLException {
		Connection conn = DriverManager.getConnection("jdbc:derby:test.db;create=true");
		
		// Set autocommit to false to allow execution of
		// multiple queries/statements as part of the same transaction.
		conn.setAutoCommit(false);
		
		return conn;
	}
	
	private void loadAuthor(Author author, ResultSet resultSet, int index) throws SQLException {
		author.setAuthorId(resultSet.getInt(index++));
		author.setLastname(resultSet.getString(index++));
		author.setFirstname(resultSet.getString(index++));
	}
	
	private void loadBook(Book book, ResultSet resultSet, int index) throws SQLException {
		book.setBookId(resultSet.getInt(index++));
		book.setAuthorId(resultSet.getInt(index++));
		book.setTitle(resultSet.getString(index++));
		book.setIsbn(resultSet.getString(index++));
		book.setPublished(resultSet.getInt(index++));		
	}
	
	public void createTables() {
		executeTransaction(new Transaction<Boolean>() {
			@Override
			public Boolean execute(Connection conn) throws SQLException {
				PreparedStatement stmt1 = null;
				PreparedStatement stmt2 = null;
				
				try {
					stmt1 = conn.prepareStatement(
						"create table authors (" +
						"	author_id integer primary key " +
						"		generated always as identity (start with 1, increment by 1), " +									
						"	lastname varchar(40)," +
						"	firstname varchar(40)" +
						")"
					);	
					stmt1.executeUpdate();
					
					stmt2 = conn.prepareStatement(
							"create table books (" +
							"	book_id integer primary key " +
							"		generated always as identity (start with 1, increment by 1), " +
							"	author_id integer constraint author_id references authors, " +
							"	title varchar(70)," +
							"	isbn varchar(15)," +
							"   published integer " +
							")"
					);
					stmt2.executeUpdate();
					
					return true;
				} finally {
					DBUtil.closeQuietly(stmt1);
					DBUtil.closeQuietly(stmt2);
				}
			}
		});
	}
	
	public void loadInitialData() {
		executeTransaction(new Transaction<Boolean>() {
			@Override
			public Boolean execute(Connection conn) throws SQLException {
				List<Author> authorList;
				List<Book> bookList;
				
				try {
					authorList = InitialData.getAuthors();
					bookList = InitialData.getBooks();
				} catch (IOException e) {
					throw new SQLException("Couldn't read initial data", e);
				}

				PreparedStatement insertAuthor = null;
				PreparedStatement insertBook   = null;

				try {
					// populate authors table (do authors first, since author_id is foreign key in books table)
					insertAuthor = conn.prepareStatement("insert into authors (lastname, firstname) values (?, ?)");
					for (Author author : authorList) {
//						insertAuthor.setInt(1, author.getAuthorId());	// auto-generated primary key, don't insert this
						insertAuthor.setString(1, author.getLastname());
						insertAuthor.setString(2, author.getFirstname());
						insertAuthor.addBatch();
					}
					insertAuthor.executeBatch();
					
					// populate books table (do this after authors table,
					// since author_id must exist in authors table before inserting book)
					insertBook = conn.prepareStatement("insert into books (author_id, title, isbn, published) values (?, ?, ?, ?)");
					for (Book book : bookList) {
//						insertBook.setInt(1, book.getBookId());		// auto-generated primary key, don't insert this
						insertBook.setInt(1, book.getAuthorId());
						insertBook.setString(2, book.getTitle());
						insertBook.setString(3, book.getIsbn());
						insertBook.setInt(4,  book.getPublished());
						insertBook.addBatch();
					}
					insertBook.executeBatch();
					
					return true;
				} finally {
					DBUtil.closeQuietly(insertBook);
					DBUtil.closeQuietly(insertAuthor);
				}
			}
		});
	}
	
	// The main method creates the database tables and loads the initial data.
	public static void main(String[] args) throws IOException {
		System.out.println("Creating tables...");
		DerbyDatabase db = new DerbyDatabase();
		db.createTables();
		
		System.out.println("Loading initial data...");
		db.loadInitialData();
		
		System.out.println("Success!");
	}
}
