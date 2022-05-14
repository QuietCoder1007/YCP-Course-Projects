package edu.ycp.cs320.booksdb;

import java.util.List;
import java.util.Scanner;

import edu.ycp.cs320.booksdb.model.Author;
import edu.ycp.cs320.booksdb.model.Book;
import edu.ycp.cs320.booksdb.model.Pair;
import edu.ycp.cs320.booksdb.persist.DatabaseProvider;
import edu.ycp.cs320.booksdb.persist.IDatabase;

public class InsertNewBookWithAuthor {
	public static void main(String[] args) throws Exception {
		Scanner keyboard = new Scanner(System.in);

		// Create the default IDatabase instance
		InitDatabase.init(keyboard);
		
		System.out.print("Enter a lastname: ");
		String lastname = keyboard.nextLine();
		
		System.out.print("Enter a firstname: ");
		String firstname = keyboard.nextLine();

		System.out.print("Enter a title: ");
		String title = keyboard.nextLine();
		
		System.out.print("Enter an isbn: ");
		String isbn = keyboard.nextLine();
		
		while(isbn.length() < 13) {
			System.out.print("Isbn MUST have 13 characters: ");
			isbn = keyboard.nextLine();
		}
		
		System.out.print("Enter a year: ");
		Integer published = keyboard.nextInt();
		
		// get the DB instance and execute transaction
		IDatabase db = DatabaseProvider.getInstance();
		List<Pair<Author, Book>> authorBookList = db.insertNewBookWithAuthor(firstname, lastname, title, isbn, published);
		
		// check if anything was returned and output the list
		if (authorBookList.isEmpty()) {
			System.out.println("No books found with author <" + lastname + ", " + firstname + ">");
			System.out.println("It is being created...");
		}
		else {
			for (Pair<Author, Book> authorBook : authorBookList) {
				Author author = authorBook.getLeft();
				Book book = authorBook.getRight();
				System.out.println(author.getLastname() + ", " + author.getFirstname() + ", " + book.getTitle() + ", " + book.getIsbn() + ", " + book.getPublished());
			}
		}
	}
}
