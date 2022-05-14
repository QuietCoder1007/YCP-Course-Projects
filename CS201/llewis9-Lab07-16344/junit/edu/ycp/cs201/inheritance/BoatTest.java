package edu.ycp.cs201.inheritance;

import static org.junit.Assert.*;

/*	------TERRAIN------
ROAD,
AIRPORT,
WATER,
MARINA,
FIELD,
FOREST,
MOUNTAIN;
*/

import org.junit.Before;
import org.junit.Test;

public class BoatTest {
	private Trip legalTrip;
	private Trip illegalTrip;
	private Boat myBoat;
	
	@Before
	public void setUp() throws Exception {
		// a Trip that can be completed by Boat
		legalTrip = new Trip(3);
		legalTrip.setHop(0, Terrain.MARINA);
		legalTrip.setHop(1, Terrain.WATER);
		legalTrip.setHop(2, Terrain.MARINA);
		
		// a Trip that cannot be completed by Boat
		// because it contains a hop through anything other than WATER
		illegalTrip = new Trip(5);
		illegalTrip.setHop(0, Terrain.MARINA);	// Not possible by Boat!
		illegalTrip.setHop(1, Terrain.FOREST);
		illegalTrip.setHop(2, Terrain.ROAD);
		illegalTrip.setHop(3, Terrain.WATER);   
		illegalTrip.setHop(4, Terrain.MARINA);
		
		myBoat = new Boat();
	}
	
	@Test
	public void testLegalTrip() throws Exception {
		assertTrue(legalTrip.isTripPossible(myBoat));
	}
	
	@Test
	public void testIllegalTrip() throws Exception {
		assertFalse(illegalTrip.isTripPossible(myBoat));
	}
}
