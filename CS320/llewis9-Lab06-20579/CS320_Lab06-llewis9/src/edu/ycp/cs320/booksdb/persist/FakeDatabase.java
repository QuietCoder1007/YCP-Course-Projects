package edu.ycp.cs320.booksdb.persist;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import edu.ycp.cs320.booksdb.model.Author;
import edu.ycp.cs320.booksdb.model.Book;
import edu.ycp.cs320.booksdb.model.Pair;

public class FakeDatabase implements IDatabase {
	
	private List<Author> authorList;
	private List<Book> bookList;
	
	public FakeDatabase() {
		authorList = new ArrayList<Author>();
		bookList = new ArrayList<Book>();
		
		// Add initial data
		readInitialData();
		
		System.out.println(authorList.size() + " authors");
		System.out.println(bookList.size() + " books");
	}

	public void readInitialData() {
		try {
			authorList.addAll(InitialData.getAuthors());
			bookList.addAll(InitialData.getBooks());
		} catch (IOException e) {
			throw new IllegalStateException("Couldn't read initial data", e);
		}
	}
	
	@Override
	public List<Pair<Author, Book>> insertNewBookWithAuthor(String firstname, String lastname, String title, String isbn, Integer published){
		List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
		for (Author author : authorList) {
			Book book = new Book();
			book.setTitle(title);
			book.setIsbn(isbn);
			book.setPublished(published);
			
			if(author.getFirstname().equalsIgnoreCase(firstname) && author.getLastname().equalsIgnoreCase(lastname)) {
				book.setAuthorId(author.getAuthorId());
			}else {
				author.setAuthorId(authorList.size());
				author.setFirstname(firstname);
				author.setLastname(lastname);
				authorList.add(author);
			}
			result.add(new Pair<Author, Book>(author, book));
			bookList.add(book);
			break;
		}
		return result;
	}
	
	@Override
	public List<Pair<Author, Book>> findAuthorAndBookByAuthorLastName(String lastname) {
		List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
		for (Author author : authorList) {
			if (author.getLastname().equalsIgnoreCase(lastname)) {
				Book book = findBookByAuthorId(author.getAuthorId());
				result.add(new Pair<Author, Book>(author, book));
			}
		}
		return result;
	}
	
	@Override
	public List<Pair<Author, Book>> findAuthorAndBookByTitle(String title) {
		List<Pair<Author, Book>> result = new ArrayList<Pair<Author,Book>>();
		for (Book book : bookList) {
			if (book.getTitle().equals(title)) {
				Author author = findAuthorByAuthorId(book.getAuthorId());
				result.add(new Pair<Author, Book>(author, book));
			}
		}
		return result;
	}

	private Author findAuthorByAuthorId(int authorId) {
		for (Author author : authorList) {
			if (author.getAuthorId() == authorId) {
				return author;
			}
		}
		return null;
	}
	
	private Book findBookByAuthorId(int authorId) {
		for (Book book: bookList) {
			if (book.getAuthorId() == authorId) {
				return book;
			}
		}
		return null;
	}

	
}
