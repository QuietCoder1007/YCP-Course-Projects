package edu.ycp.cs201.disks;

/**
 * An instance of the Disk class represents a disk
 * to be placed on the game board.
 */
public class Disk {
	// TODO: add fields.
	// You need to store information about the
	// Disk's x and y coordinate, its radius,
	// and its color.
	private double x;
	private double y;
	private double radius;
	private DiskColor color;

	/**
	 * Constructor.
	 * Store x, y, radius, and Color values in the fields
	 * of the object being initialized.
	 * 
	 * @param x the x coordinate of the new Disk
	 * @param y the y coordinate of the new Disk
	 * @param radius the radius of the new Disk
	 * @param color the color of the new Disk
	 */
	public Disk(double x, double y, double radius, DiskColor color) {
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.color = color;
	}
	
	/**
	 * @return the Disk's x coordinate
	 */
	public double getX() {
		return this.x;
	}
	
	/**
	 * @return the Disk's y coordinate
	 */
	public double getY() {
		return this.y;
	}
	
	/**
	 * @return the Disk's radius
	 */
	public double getRadius() {
		return this.radius;
	}
	
	/**
	 * @return the Disk's color
	 */
	public DiskColor getColor() {
		return this.color;
	}
	
	/**
	 * Return true if this Disk overlaps
	 * the Disk given as the parameter, false otherwise.
	 * 
	 * @param other another Disk
	 * @return true if the two Disks overlap, false if they don't
	 */
	public boolean overlaps(Disk other) {
		double diffX = Math.pow(getX()-other.x, 2);
		double diffY = Math.pow(getY()-other.y, 2);
		double minDist = Math.sqrt(diffX + diffY);
		double distBetweenDisks = minDist - getRadius() - other.radius;
		
		if(distBetweenDisks <= 0) {
			return true;
		}
		return false;
	}

	/**
	 * Return true if this Disk is out of bounds, meaning that
	 * it is not entirely enclosed by rectangle whose width and
	 * height are given by the two parameters. 
	 * Assume that the upper-left hand corner of the rectangle
	 * is at (0,0), that x coordinates increase going to
	 * the right, and that y coordinates increase going down.
	 * 
	 * @param width   the width of a rectangle
	 * @param height  the height of a rectangle
	 * @return false if the Disk fits entirely within the rectangle,
	 *         true if at least part of the Disk lies outside the
	 *         rectangle
	 */
	public boolean isOutOfBounds(double width, double height) {
		if(getX() - getRadius() > 0 && getX() + getRadius() < width) {
			if(getY() - getRadius() > 0 && getY() + getRadius() < height) {
				return false;
			}
		}
		return true;
	}
}