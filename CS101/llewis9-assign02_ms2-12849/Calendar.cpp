		// Le Quient Lewis II
	//2-19-2019
// Milestone 1: Obtain user input for the month and year, determine the number of days in the month, determine the first of the month and the corresponding days, and print the output for the number of days in the month and the first day of the month
// Milestone 2: Validate user input for Month to be in 1-12 and Year greater than -4713; Print name of Month and Year and Days of Week; Print each day to have 11 spaces between them; Print the first day of the week and the following days of the week with 11 spaces and proper formatting

//CS101 Assignment 2 - Fall 2018
#include <stdio.h>
#include <math.h>

int main() 
{
	int Month, Year, Days, JulianDay, DoW;
	float Leap;
		
	//Ask for input from user
	printf("Enter month and year: ");
	scanf("%i %i",&Month,&Year);
	
	//Calculate Julian Day
	JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				
	//Calculate first day of week
	DoW = (JulianDay + 1) % 7;
	
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
				
				//Calculate first day of week
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday\n"); 
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
			//Initialize variable for Month (March)
			else if (Month == 3)
			{
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nJanuary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nJanuary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (May)
			else if (Month == 5)
			{	
				if (DoW == 0)
				{
				//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
			}
			//Initialize variable for Month (July)
			else if (Month == 7)
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nJuly %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nJuly %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nJuly %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nJuly %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nJuly %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nJuly %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nJuly %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (August)
			else if (Month == 8)
			{
				
				if (DoW == 0)
				{
				//Print month and year
					printf("\nAugust %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nAugust %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nAugust %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nAugust %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nAugust %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nAugust %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nAugust %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (October)
			else if (Month == 10)
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				
				}
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
			
			//Initialize variable for Month (December)
			else if (Month == 12)
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nMay %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
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
				if (DoW == 0)
				{
				//Print month and year
					printf("\nApril %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nApril %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nApril %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nApril %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nApril %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nApril %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nApril %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (June)
			else if (Month == 6) 
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nJune %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nJune %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nJune %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nJune %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nJune %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nJune %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nJune %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (September)				
			else if (Month == 9)
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nSeptember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nSeptember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nSeptember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nSeptember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nSeptember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nSeptember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nSeptember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			//Initialize variable for Month (November)
			else if (Month == 11)
			{
				if (DoW == 0)
				{
				//Print month and year
					printf("\nNovember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
	
				}
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nNovember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nNovember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nNovember %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nNovember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nNovember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if (j >= 10 && j <= Days)
							{
								if (j == 10 || j == 17 || j == 24 || j == 31)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nNovember %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 2 || j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23 || j == 30)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
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
				
				//Calculate first day of week
				DoW = (JulianDay + 1) % 7;
				
				printf("The month has %i days", Days);
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday\n"); 
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						if (i == 1)
						{
							printf("          ");
							printf(" 1          2          3          4          5          6");
						}
					}
					for(int j=7; j<=Days; j++) 
						{
							if (j >= 7 && j <= 9)
							{
								if (j == 7)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 14 || j == 21 || j == 28)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 10 || j == 17 || j == 24)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
				
			else 
			{
				Days = 28;
				printf("There are %i days in the month", Days);
				
				//Calculate Julian Day
				JulianDay =  (1461 * (Year + 4800 + (Month - 14)/12))/4 +(367 * (Month - 2 - 12 * ((Month - 14)/12)))/12 - (3 * ((Year + 4900 + (Month - 14)/12)/100))/4 + 1 - 32075;
				
				//Calculate first day of week
				DoW = (JulianDay + 1) % 7;
				
				//Calculate the first day of the week (Sunday)
				if (DoW == 0)
				{
					printf("\nThe month starts on a Sunday\n"); 
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i+=0)
					{	
						break;
					}
					for(int j=1; j<=Days; j++) 
						{
							if (j >= 1 && j <= 9)
							{
								if (j == 8)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 15 || j == 22 || j == 29)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Monday)
				else if (DoW == 1)
				{
					printf("\nThe month starts on a Monday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i <= DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Tuesday)
				else if (DoW == 2)
				{
					printf("\nThe month starts on a Tuesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 1)
							printf("  1          2          3          4          5");
					}
					for(int j=6; j<=Days; j++) 
						{
							if (j >= 6 && j <= 9)
							{
								if (j == 6)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 13 || j == 20 || j == 27)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Wednesday)
				else if (DoW == 3)
				{
					printf("\nThe month starts on a Wednesday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					//Calendar that works :D
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 2)
							printf("    1          2          3          4");
					}
					for(int j=5; j<=Days; j++) 
						{
							if (j >= 5 && j <= 9)
							{
								if (j == 5)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 12 || j == 19 || j == 26)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Thursday)
				else if (DoW == 4)
				{
					printf("\nThe month starts on a Thursday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 3)
							printf("    1          2          3");
					}
					for(int j=4; j<=Days; j++) 
						{
							if (j >= 4 && j <= 9)
							{
								if (j == 4)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 11 || j == 18 || j == 25)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Friday)
				else if (DoW == 5)
				{
					printf("\nThe month starts on a Friday\n");
					
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 4)
							printf("     1          2");
					}
					for(int j=3; j<=Days; j++) 
						{
							if (j >= 3 && j <= 9)
							{
								if (j == 3)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 10 || j == 17 || j == 24)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
				
				//Calculate the first day of the week (Saturday)
				else if (DoW == 6)
				{
			
					printf("\nThe month starts on a Saturday\n");
				
					//Print month and year
					printf("\nFebruary %i", Year);
					
					printf("\nSunday     Monday     Tuesday    Wednesday  Thursday   Friday     Saturday\n");
					for (int i=0; i < DoW; i++)
					{	
						printf("          ");
						if (i == 5)
							printf("      1\n");
					}
					for(int j=2; j<=Days; j++) 
						{
							if (j >= 2 && j <= 9)
							{
								if (j == 9)
								{
									printf("\n%i          ",j);
								}
								else
								{
									printf("%i          ",j);
								}
							}		
							else if ((j >= 10 && j <= Days))
							{
								if (j == 16 || j == 23)
								{
									printf("\n%i         ",j);
								}	
								else
								{
									printf("%i         ",j);
								}
							}
						}
				}
			}
		}	
	}
	return 0;
}