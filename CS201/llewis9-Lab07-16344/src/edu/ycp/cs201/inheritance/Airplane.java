package edu.ycp.cs201.inheritance;
/*	------TERRAIN------
	ROAD,
	AIRPORT,
	WATER,
	MARINA,
	FIELD,
	FOREST,
	MOUNTAIN;
  */


public class Airplane extends Vehicle {

	@Override
	public boolean endTrip(Terrain t) {
		if ( t == Terrain.AIRPORT ) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean move(Terrain t) {
		if ( t == Terrain.WATER || t == Terrain.MOUNTAIN || t == Terrain.FOREST || t == Terrain.FIELD || t == Terrain.MARINA || t == Terrain.ROAD || t == Terrain.AIRPORT) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean startTrip(Terrain t) {
		if ( t == Terrain.AIRPORT ) {
			return true;
		} else {
			return false;
		}
	}
}