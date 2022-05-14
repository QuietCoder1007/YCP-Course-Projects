package edu.ycp.cs201.iterator;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;

import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class AlgorithmTest {
	private List<String> first;
	private List<String> second;

	@Before
	public void setUp() {
		first = Arrays.asList(new String[]{"F","P","L","C","W","J","G"});
		second = Arrays.asList(new String[]{"N","H","K","X"});
	}

	@Test
	public void testInterleave() throws Exception {
		// Interleave the elements in the first and second lists
		Iterator<String> i = Algorithm.interleave(first, second).iterator();
		
		// Verify that the result is the interleaving of the original lists.
		// Note that the first list has more elements than the second,
		// so that when the second list is exhausted (at X), the remainder
		// of the result list contains only elements from the first list.
		assertEquals("F", i.next());
		assertEquals("N", i.next());
		assertEquals("P", i.next());
		assertEquals("H", i.next());
		assertEquals("L", i.next());
		assertEquals("K", i.next());
		assertEquals("C", i.next());
		assertEquals("X", i.next());
		assertEquals("W", i.next());
		assertEquals("J", i.next());
		assertEquals("G", i.next());
		assertFalse(i.hasNext());
	}

	@Test
	public void testMerge() throws Exception {
		// Sort first and second lists
		Collections.sort(first);
		Collections.sort(second);
		
		// Merge the sorted lists
		Iterator<String> i = Algorithm.mergeSortedLists(first, second).iterator();
		
		// Verify that the result has all of the elements in the original lists,
		// in sorted order
		assertEquals("C", i.next());
		assertEquals("F", i.next());
		assertEquals("G", i.next());
		assertEquals("H", i.next());
		assertEquals("J", i.next());
		assertEquals("K", i.next());
		assertEquals("L", i.next());
		assertEquals("N", i.next());
		assertEquals("P", i.next());
		assertEquals("W", i.next());
		assertEquals("X", i.next());
		assertFalse(i.hasNext());
	}
}
