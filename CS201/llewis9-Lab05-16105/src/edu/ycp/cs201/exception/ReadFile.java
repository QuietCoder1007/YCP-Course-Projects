package edu.ycp.cs201.exception;

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ReadFile {
	//
	// Requirements:
	// - do not add "throws IOException" (or any other throws clause)
	//   to the main() method
	// - do not test whether or not the requested file exists
	//   before trying to open it
	// - use a try/finally block to make sure that the
	//   file reader or input stream is closed
	//
	public static void main(String[] args) {
		// Prompt the user to enter a filename
		Scanner keyboard = new Scanner(System.in); 
		System.out.println("What file do you want to access?");
		String fileName = keyboard.next();
		keyboard.close();
		
		File file = new File(fileName);
		FileReader fReader = null;
		BufferedReader bReader = null;
		
		
		// Print the contents of the file to System.out
		System.out.println(file);
		try {
			fReader = new FileReader(file);
			
			bReader = new BufferedReader(fReader);
			
			String read = bReader.readLine();
			
			System.out.println(read);
			
		} catch (FileNotFoundException e){
			System.out.println(fileName + " does not not appear to exist.");
			
		// If the file can't be opened, or if an
		// IOException occurs, print an error message
		} catch (IOException e){
			System.out.println("Error: " + e.getMessage());
		} finally {
				try {
					if(bReader != null) { 
						bReader.close();
					}
					if(fReader != null) {
						fReader.close();
					}
				} catch (IOException e){
					System.out.println("Error: " + e.getMessage());
				}
		}
	}
}
