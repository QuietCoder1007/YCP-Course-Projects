		// Le Quient Lewis II
	//2-19-2019
// Obtain user input for the month and year, determine the number of days in the month, determine the first of the month and the corresponding days, and print the output for the number of days in the month and the first day of the month

//CS101 Assignment 2 - Fall 2018
#include <stdio.h>

int main() {
	int Month, Year, Days, JulianDay, DoW;
	float Leap;
		
	//Ask for input from user
	printf("Enter month and year: ");
	scanf("%i %i",&Month,&Year);
	
	Leap = Year % 4;
	
	// Test for invalid inputs
	while ((Month <= 0 || Month >= 13) && (Year <= -4713))
	{
		printf("Okay...you're gonna get it right this time. I know it!");
		printf("Re-enter your month and year please: ");
		scanf("%i %i",&Month,&Year);
	}
	
	//Test for valid inputs for Month and Year
	if((Month > 0 && Month < 13) && (Year > -4713))
	{
		if ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7) || (Month == 8) || (Month == 10) || (Month == 12))
		{
		//Months with 31 Days
		Days = 31;
		printf("There are %i days in the month", Days);
		
			//Initialize variable for Month (January)
			if (Month == 1)
			{
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (March)
			else if (Month == 3)
			{
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (May)
			else if (Month == 5)
			{
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (July)
			else if (Month == 7)
			{
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (August)
			else if (Month == 8)
			{
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (October)
			else if (Month == 10)
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
			
			//Initialize variable for Month (December)
			else if (Month == 12)
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
		}
		else if ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))
		{
			Days = 30;
			printf("There are %i days in the month", Days);
			
			//Initialize variable for Month (April)
			if (Month == 4)
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (June)
			else if (Month == 6) 
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week
				if (DoW == 0)
				{
					printf("The month starts on a Sunday"); 
				}
				else if (DoW == 1)
				{
					printf("The month starts on a Monday");
				}
				else if (DoW == 2)
				{
					printf("The month starts on a Tuesday");
				}
				else if (DoW == 3)
				{
					printf("The month starts on a Wednesday");
				}
				else if (DoW == 4)
				{
					printf("The month starts on a Thursday");
				}
				else if (DoW == 5)
				{
					printf("The month starts on a Friday");
				}
				else if (DoW == 6)
				{
					printf("The month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (September)				
			else if (Month == 9)
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week
				if (DoW == 0)
				{
					printf("The month starts on a Sunday"); 
				}
				else if (DoW == 1)
				{
					printf("The month starts on a Monday");
				}
				else if (DoW == 2)
				{
					printf("The month starts on a Tuesday");
				}
				else if (DoW == 3)
				{
					printf("The month starts on a Wednesday");
				}
				else if (DoW == 4)
				{
					printf("The month starts on a Thursday");
				}
				else if (DoW == 5)
				{
					printf("The month starts on a Friday");
				}
				else if (DoW == 6)
				{
					printf("The month starts on a Saturday");
				}
			}
				
			//Initialize variable for Month (November)
			else if (Month == 11)
			{
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week
				if (DoW == 0)
				{
					printf("The month starts on a Sunday"); 
				}
				else if (DoW == 1)
				{
					printf("The month starts on a Monday");
				}
				else if (DoW == 2)
				{
					printf("The month starts on a Tuesday");
				}
				else if (DoW == 3)
				{
					printf("The month starts on a Wednesday");
				}
				else if (DoW == 4)
				{
					printf("The month starts on a Thursday");
				}
				else if (DoW == 5)
				{
					printf("The month starts on a Friday");
				}
				else if (DoW == 6)
				{
					printf("The month starts on a Saturday");
				}
			}	
		}	
				//Initialize variable for Month (February)
		else if (Month == 2) 
		{
			if (Leap == 0)
			{	
				Days = 29;

				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
				
			else 
			{
				Days = 28;
				
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday"); 
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday");
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday");
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday");
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday");
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday");
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
					printf("\nThe month starts on a Saturday");
				}
			}
		}	 
	}	
	return 0;
}