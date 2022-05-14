package edu.ycp.cs201.inheritance;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class AirplaneTest {
	private Trip legalTrip;
	private Trip illegalTrip;
	private Airplane myAirplane;
	
	@Before
	public void setUp() throws Exception {
		// a Trip that can be completed by Airplane
		legalTrip = new Trip(9);
		legalTrip.setHop(0, Terrain.AIRPORT);
		legalTrip.setHop(1, Terrain.FIELD);
		legalTrip.setHop(2, Terrain.MOUNTAIN);
		legalTrip.setHop(3, Terrain.AIRPORT);
		legalTrip.setHop(4, Terrain.FOREST);
		legalTrip.setHop(5, Terrain.ROAD);
		legalTrip.setHop(6, Terrain.WATER);   
		legalTrip.setHop(7, Terrain.MARINA);
		legalTrip.setHop(8, Terrain.AIRPORT);
		
		// a Trip that can be completed by Airplane
		// because it contains a hop through anything
		illegalTrip = new Trip(9);
		legalTrip.setHop(0, Terrain.AIRPORT);
		legalTrip.setHop(1, Terrain.FIELD);
		legalTrip.setHop(2, Terrain.MOUNTAIN);
		legalTrip.setHop(3, Terrain.AIRPORT);
		legalTrip.setHop(4, Terrain.FOREST);
		legalTrip.setHop(5, Terrain.ROAD);
		legalTrip.setHop(6, Terrain.WATER);   
		legalTrip.setHop(7, Terrain.AIRPORT);

		
		myAirplane = new Airplane();
	}
	
	@Test
	public void testLegalTrip() throws Exception {
		assertTrue(legalTrip.isTripPossible(myAirplane));
	}
	
	@Test
	public void testIllegalTrip() throws Exception {
		assertFalse(illegalTrip.isTripPossible(myAirplane));
	}
}
