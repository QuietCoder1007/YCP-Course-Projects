package edu.ycp.cs201.inheritance;

/**
 * A Trip is a sequence of Terrain types
 * over which different kinds of Vehicles
 * can move.
 */
public class Trip {
	private Terrain[] hops;

	/**
	 * Constructor.
	 * 
	 * @param numHops number of hops (through different kinds of terrain)
	 *        that the Trip requires
	 */
	public Trip(int numHops) {
		if (numHops < 2) {
			throw new IllegalArgumentException("Trips must have at least a start and finish");
		}
		this.hops = new Terrain[numHops];
	}
	
	/**
	 * Set one of the hops of the trip
	 * (0 is first).
	 * 
	 * @param hop which hop of the trip to set
	 * @param t   the kind of Terrain that this hop requires
	 */
	public void setHop(int hop, Terrain t) {
		hops[hop] = t;
	}
	
	/**
	 * Return whether or not it is possible to make
	 * this Trip with the given Vehicle.
	 * 
	 * @param v a Vehicle
	 * @return true if the trip is possible, false if not
	 */
	public boolean isTripPossible(Vehicle v) {
		// Check the first hop
		if (!v.startTrip(hops[0])) {
			return false;
		}
		
		// Check all hops between the first and last
		for (int i = 1; i < hops.length - 1; i++) {
			if (!v.move(hops[i])) {
				return false;
			}
		}
		
		// Check the last hop
		if (!v.endTrip(hops[hops.length - 1])) {
			return false;
		}
		
		// success!
		return true;
	}
}
