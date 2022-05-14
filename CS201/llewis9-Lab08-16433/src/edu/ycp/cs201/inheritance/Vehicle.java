package edu.ycp.cs201.inheritance;

/**
 * Abstract class representing a vehicle.
 */
public abstract class Vehicle {
	private double maxSpeed;
	
	public Vehicle(double maxSpeed) {
		this.maxSpeed = maxSpeed;
	}
	
	/**
	 * Get the vehicle's maximum speed.
	 */
	public double getMaxSpeed() {
		return maxSpeed;
	}
	
	/**
	 * Is it possible for this Vehicle to start a trip
	 * at the given kind of Terrain?
	 * 
	 * @param t a kind of Terrain
	 * @return true if this Vehicle can start at the kind of Terrain,
	 *         false otherwise
	 */
	public abstract boolean startTrip(Terrain t);

	/**
	 * Is it possible for this Vehicle to end a trip
	 * at the given kind of Terrain?
	 * 
	 * @param t a kind of Terrain
	 * @return true if this Vehicle can end at the kind of Terrain,
	 *         false otherwise
	 */
	public abstract boolean endTrip(Terrain t);
	
	/**
	 * Is it possible for this Vehicle to continue a trip
	 * at the given kind of Terrain?
	 * 
	 * @param t a kind of Terrain
	 * @return true if this Vehicle can continue at the kind of Terrain,
	 *         false otherwise
	 */
	public abstract boolean move(Terrain t);
}
