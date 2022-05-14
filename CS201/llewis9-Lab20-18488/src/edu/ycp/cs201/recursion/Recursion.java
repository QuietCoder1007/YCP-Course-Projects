package edu.ycp.cs201.recursion;

public class Recursion {
	//
	// Return the factorial of the parameter n.
	// The factorial of n is defined as 
	//
	//    1 * 2 * 3 * ... * (n-1) * n
	//
	// Assume that n is positive.
	//
	// Examples:
	//     factorial(3) returns 6
	//     factorial(4) returns 24
	//     factorial(5) returns 120
	//
	public static int factorial(int n) {
		if(n <= 1) {return 1;}
		return n * factorial(n-1);
	}
	
	//
	// Return a string which reverses the characters
	// of the given string.
	//
	// Examples:
	//     reverseString("abc") returns "cba"
	//     reverseString("adanishcustard") returns "dratsuchsinada"
	//
	// Hint: use the charAt(int) and substring(int,int) methods
	// to divide the string into two parts.
	//
	public static String reverseString(String s) {
		if(s.isEmpty()) {return "";}
		
		return reverseString(s.substring(1)) + s.charAt(0);
	}
	
	//
	// Return the number of even digits in the decimal representation
	// of n.
	//
	// Examples:
	//     countEvenDigits(0) returns 1
	//     countEvenDigits(42) returns 2
	//     countEvenDigits(131) returns 0
	//     countEvenDigits(90125) returns 2
	//
	// Hint: n % 10 is the value of the rightmost digit.
	// n / 10 contains all of the digits except the rightmost
	// digit.
	//
	public static int countEvenDigits(int n) {
		int count = 0;
		if(n == 0) { return count += 1;}
		if(n / 10 != 0) {
			int lastDigit = n % 10;
			
			count += countEvenDigits(n/10);

			if(lastDigit % 2 == 0) {
				count++;
			}
		}
		else {
			if(n % 2 == 0) {
				count++;
			}
		}
		return count;
	}
	
	//
	// Convert given string, which contains a sequence of
	// decimal digits, to the integer value represented by
	// the sequence of digits.
	//
	// You don't need to handle strings beginning with "-"
	// (representing a negative value.)
	// 
	// Examples:
	//     stringToInt("42") returns 42
	//     stringToInt("131") returns 131
	//
	// Hint: use the charAt(int) and substring(int,int) methods
	// to divide the string into two parts.
	//
	public static int stringToInt(String s) {
		int n = 0;

		int val = Integer.parseInt(s.substring(n, n+1));
		
		if(n == s.length() - 1) {
			return val;
		}
		
		return val * (int)(Math.pow(10, s.length() - 1)) + stringToInt(s.substring(n+1));
	}
}
