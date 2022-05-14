		//Le Quient Lewis II
	//February 8, 2019
//

// TODO: add your code to this file
#include <stdio.h>
#include <math.h>

// To start the code
 int main(){
	 
	 // Meters will be constant
	int meters;	
	
	// Float variables for time, velocities in m/s, ft/s, and mph
	float Secs, Velocity, MilesPH, FeetperSec;
		
		//Prompt user to add a variable
		printf("Enter the initial height of the object in meters: ");
		
		//Scan for user input
		scanf("%i",&meters);
		
		// time = square root of (2 * Meters over 9.81)
		Secs = sqrt((2*meters)/9.81);
				
		// Velocity = (1/2 gravity) + Seconds^2 + meters
		Velocity = 9.81*Secs;
		
		// Velocity in feet per second
		FeetperSec = Velocity * 3.26;

		// Velocity in miles per hour
		MilesPH = Velocity * (3600.0/1609.0);		
		
		//Tell user how long the object fell for
		printf("The object took %.2f secs to fall.\n", Secs);

		//Tell user the velocity of the object on impact in meters/sec, Feet/sec, and Miles per hour 
		printf("The object velocity of the object was:\n               				%.1f m/s\n               				%.1f ft/sec\n               				%.1f mph", Velocity, FeetperSec, MilesPH);
	
	return 0;
}