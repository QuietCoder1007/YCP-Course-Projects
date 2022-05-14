package edu.ycp.cs201.inheritance;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class CarTest {
	private Trip legalTrip;
	private Trip illegalTrip;
	private Car myCar;
	
	@Before
	public void setUp() throws Exception {
		// a Trip that can be completed by Car
		legalTrip = new Trip(4);
		legalTrip.setHop(0, Terrain.AIRPORT);
		legalTrip.setHop(1, Terrain.ROAD);
		legalTrip.setHop(2, Terrain.ROAD);
		legalTrip.setHop(3, Terrain.MARINA);
		
		// a Trip that cannot be completed by Car
		// because it contains a hop through WATER
		illegalTrip = new Trip(5);
		illegalTrip.setHop(0, Terrain.WATER);
		illegalTrip.setHop(1, Terrain.ROAD);
		illegalTrip.setHop(2, Terrain.ROAD);
		illegalTrip.setHop(3, Terrain.WATER);   // Not possible by Car!
		illegalTrip.setHop(4, Terrain.MARINA);
		
		myCar = new Car();
	}
	
	@Test
	public void testLegalTrip() throws Exception {
		assertTrue(legalTrip.isTripPossible(myCar));
	}
	
	@Test
	public void testIllegalTrip() throws Exception {
		assertFalse(illegalTrip.isTripPossible(myCar));
	}
}
