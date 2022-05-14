package edu.ycp.cs201.inheritance;

public class Car extends Vehicle {
	
	public Car(double maxSpeed) {
		super(maxSpeed);
	}

	@Override
	public boolean endTrip(Terrain t) {
		if ( t == Terrain.AIRPORT || t == Terrain.MARINA ) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean move(Terrain t) {
		if ( t == Terrain.AIRPORT || t == Terrain.MARINA || t == Terrain.ROAD ) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean startTrip(Terrain t) {
		if ( t == Terrain.AIRPORT || t == Terrain.MARINA ) {
			return true;
		} else {
			return false;
		}
	}
}
