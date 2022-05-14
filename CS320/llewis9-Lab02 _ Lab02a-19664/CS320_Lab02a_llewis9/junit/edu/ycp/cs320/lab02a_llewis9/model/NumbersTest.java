package edu.ycp.cs320.lab02a_llewis9.model;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import edu.ycp.cs320.lab02a_llewis9.model.Numbers;

public class NumbersTest {
	private Numbers model;
	
	@Before
	public void setUp() {
		model = new Numbers();
	}
	
	@Test
	public void testSetFirst() {
		model.setFirst(5.0);
		assertEquals(5.0, model.getFirst(), 0.0);
	}
	
	public void testSetSecond() {
		model.setSecond(5.0);
		assertEquals(5.0, model.getSecond(), 0.0);
	}
	
	public void testSetThird() {
		model.setThird(5.0);
		assertEquals(5.0, model.getThird(), 0.0);
	}
	
	public void testSetResult() {
		model.setResult(555.0);
		assertEquals(555.0, model.getResult(), 0.0);
	}
}
