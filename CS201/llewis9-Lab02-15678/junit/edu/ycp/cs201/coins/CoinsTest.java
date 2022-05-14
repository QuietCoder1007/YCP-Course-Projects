package edu.ycp.cs201.coins;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class CoinsTest {
	private Coins empty;
	private Coins oneOfEach;
	private Coins fiveQuartersOnePenny;
	private Coins twelveDimesOneNickelOnePenny;
	
	@Before
	public void setUp() throws Exception {
		empty = new Coins();
		oneOfEach = new Coins(1, 1, 1, 1);
		fiveQuartersOnePenny = new Coins(1, 0, 0, 5);
		twelveDimesOneNickelOnePenny = new Coins(1, 1, 12, 0);
	}
	
	@Test
	public void testFindCentsValue() throws Exception {
		assertEquals(0, empty.findCentsValue());
		assertEquals(41, oneOfEach.findCentsValue());
		assertEquals(126, fiveQuartersOnePenny.findCentsValue());
		assertEquals(126, twelveDimesOneNickelOnePenny.findCentsValue());
	}
	
	@Test
	public void testFindDollars() throws Exception {
		assertEquals(0, empty.findDollars());
		assertEquals(0, oneOfEach.findDollars());
		assertEquals(1, fiveQuartersOnePenny.findDollars());
		assertEquals(1, twelveDimesOneNickelOnePenny.findDollars());
	}
	
	@Test
	public void testFindChange() throws Exception {
		assertEquals(0, empty.findChange());
		assertEquals(41, oneOfEach.findChange());
		assertEquals(26, fiveQuartersOnePenny.findChange());
		assertEquals(26, twelveDimesOneNickelOnePenny.findChange());
	}
}
