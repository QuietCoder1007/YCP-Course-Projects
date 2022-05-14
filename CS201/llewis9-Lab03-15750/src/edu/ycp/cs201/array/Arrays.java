package edu.ycp.cs201.array;

import java.util.Scanner;

public class Arrays {
	public static String how = "How many integers?";
	public static String please = "Please enter ";
	public static String vals = " values";
	public static String entered = "You entered the following values:";
	public static String revrse1 = "Now I am going to reverse the array for you...";
	public static String revrse2 = "Here are the reversed array values:";
	/**
	 * Using the given Scanner object,
	 * read in the given number of integer values
	 * and return them in an array.
	 * 
	 * @param keyboard    the Scanner object to use
	 * @param numElements the number of integer values to read
	 * @return an array containing the integer values read from the keyboard
	 */
	public static int[] readArray(Scanner keyboard, int numElements) {
		int[] arr = new int[numElements] ;
		int a;
		for(int i=0; i<numElements; i++){
			a = keyboard.nextInt();
			arr[i] = a;
		}
		return arr;
	}
	
	/**
	 * Print out the values of all of the elements in the
	 * given array.
	 * 
	 * @param arr an array
	 */
	public static void printArray(int[] arr) {
		for(int i=0; i<arr.length; i++)
		System.out.println(arr[i]);
	}
	
	/**
	 * Reverse the elements of the given array.
	 * 
	 * @param arr an array
	 */
	public static void reverseArray(int[] arr) {
		int max = arr.length - 1;
		int temp; 
		for(int i=0; i<arr.length/2; i++) {
			temp = arr[i];
			arr[i]=arr[max];
			arr[max] = temp;
			max--;
			
		}
	}
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		int[] arr;
		
		int numElements;
		
		System.out.println(how);
		numElements = keyboard.nextInt();
		
		System.out.println(please + numElements + vals);
		arr = readArray(keyboard, numElements);
		
		System.out.println(entered);
		printArray(arr);
		

		System.out.println(revrse1);
		reverseArray(arr);
		
		System.out.println(revrse2);
		printArray(arr);
	}
}
