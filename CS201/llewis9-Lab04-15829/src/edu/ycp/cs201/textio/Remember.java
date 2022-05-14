package edu.ycp.cs201.textio;

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Remember {
	public static void main(String[] args) throws IOException {
		Scanner keyboard = new Scanner(System.in);	
		String fileName = "H:/CS201/Workspace/Ranner.txt";
			File f = new File(fileName);
			FileReader fileReader = new FileReader(fileName);
			BufferedReader reader = new BufferedReader(fileReader);
			String user = reader.readLine();
			
			
			if (user == null) {
				System.out.println("You are my first runner.");
			} else {
				System.out.println("I was ran by " + user + " last.");
			}
			
			System.out.print("Who are you?");
			user = keyboard.next();
			
			System.out.print("Ok, " + user + ", I'm writing your name to a file.");
			FileWriter fileWriter = new FileWriter(fileName);
			fileWriter.write(user);
			fileWriter.close();
			
			
			
	}
}
