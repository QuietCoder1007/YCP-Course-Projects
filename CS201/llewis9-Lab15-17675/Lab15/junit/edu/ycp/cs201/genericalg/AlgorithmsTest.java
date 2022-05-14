package edu.ycp.cs201.genericalg;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;

import junit.framework.TestCase;

public class AlgorithmsTest extends TestCase {
	// A comparator which compares Strings by length
	private static Comparator<String> stringLenComparator = new Comparator<String>() {
		@Override
		public int compare(String left, String right) {
			return left.length() - right.length();
		}
	};
	
	private ArrayList<String> names;
	private LinkedList<Integer> nums;
	private HashSet<String> colors;
	
	
	@Override
	protected void setUp() throws Exception {
		names = new ArrayList<String>();
		names.add("Carl");
		names.add("Alice");
		names.add("Bob");
		names.add("Delores");
		names.add("Zora");
		names.add("Yossarian");
		names.add("Zebulon");
		
		nums = new LinkedList<Integer>();
		nums.add(54);
		nums.add(17);
		nums.add(73);
		nums.add(40);
		nums.add(58);
		nums.add(24);
		
		colors = new HashSet<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Green");
		colors.add("Puce");
		colors.add("Yellow");
		colors.add("Cerulean");
	}

	public void testFindMin() throws Exception {
		assertEquals("Alice", Algorithms.findMin(names));
		assertEquals((Integer) 17, Algorithms.findMin(nums));
		assertEquals("Blue", Algorithms.findMin(colors));
	}
	
	public void testFindMinComparator() throws Exception {
		assertEquals("Bob", Algorithms.findMin(names, stringLenComparator));
		assertEquals("Red", Algorithms.findMin(colors, stringLenComparator));
	}
	
	public void testFindMax() throws Exception {
		assertEquals("Zora", Algorithms.findMax(names));
		assertEquals((Integer) 73, Algorithms.findMax(nums));
		assertEquals("Yellow", Algorithms.findMax(colors));
	}
	
	public void testFindMaxComparator() throws Exception {
		assertEquals("Yossarian", Algorithms.findMax(names, stringLenComparator));
		assertEquals("Cerulean", Algorithms.findMax(colors, stringLenComparator));
	}
	
	public void testSequentialSearch() throws Exception {
		assertEquals(4, Algorithms.sequentialSearch(names, "Zora"));
		assertEquals(6, Algorithms.sequentialSearch(names, "Zebulon"));
		assertEquals(-1, Algorithms.sequentialSearch(names, "Anna"));
		
		assertEquals(4, Algorithms.sequentialSearch(nums, 58));
		assertEquals(0, Algorithms.sequentialSearch(nums, 54));
		assertEquals(1, Algorithms.sequentialSearch(nums, 17));
		assertEquals(-1, Algorithms.sequentialSearch(nums, 99));
	}
}
