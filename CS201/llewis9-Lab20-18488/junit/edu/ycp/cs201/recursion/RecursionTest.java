package edu.ycp.cs201.recursion;

import junit.framework.TestCase;

public class RecursionTest extends TestCase {
	public void testFactorial() throws Exception {
		assertEquals(1, Recursion.factorial(1));
		assertEquals(2, Recursion.factorial(2));
		assertEquals(6, Recursion.factorial(3));
		assertEquals(24, Recursion.factorial(4));
		assertEquals(120, Recursion.factorial(5));
	}
	
	public void testReverseString() throws Exception {
		assertEquals("cba", Recursion.reverseString("abc"));
		assertEquals("abcDEF", Recursion.reverseString("FEDcba"));
		assertEquals("dratsuchsinada", Recursion.reverseString("adanishcustard"));
		assertEquals("amanaplanacanalpanama", Recursion.reverseString("amanaplanacanalpanama"));
	}
	
	public void testCountEvenDigits() throws Exception {
		assertEquals(1, Recursion.countEvenDigits(0));
		assertEquals(2, Recursion.countEvenDigits(42));
		assertEquals(0, Recursion.countEvenDigits(131));
		assertEquals(2, Recursion.countEvenDigits(90125));
	}
	
	public void testStringToInt() throws Exception {
		assertEquals(42, Recursion.stringToInt("42"));
		assertEquals(121, Recursion.stringToInt("121"));
		assertEquals(90125, Recursion.stringToInt("90125"));
		assertEquals(999, Recursion.stringToInt("999"));
		assertEquals(0, Recursion.stringToInt("0"));
		assertEquals(6, Recursion.stringToInt("6"));
	}
}
