package edu.ycp.cs201.dogyears;

import java.util.Scanner;

public class DogYears {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);  

	    System.out.println("What is your name?\n");
	    String name = keyboard.next();               
	    
	    System.out.println("How old are you " + name +"?\n");
	    int years = keyboard.nextInt();
	    
	    int dogYears = years * 7;
	    System.out.println(name + ", you are " + dogYears+" years old in dog years!");
	}
}
