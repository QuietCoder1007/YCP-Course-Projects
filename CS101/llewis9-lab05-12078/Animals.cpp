// TODO: add your code to this file
#include <stdio.h>
int main () {
	int mammal, marsupial, feathers;
	
	//Are you a mammal?
	printf("Are you a mammal?: (1=yes, 0=no) ");
	scanf ("%i",&mammal);

	if (mammal == 1)
	{
	//Are you a marsupial?
	printf("Are you a marsupial?: (1=yes, 0=no) ");
	scanf ("%i",&marsupial);
		if (marsupial == 1)
			printf("You are a kangaroo.");
		else if (marsupial == 0)
			printf("You are a horse.");
		else 
			printf("Google what you are and come back...");
	}	
		
	else if (mammal == 0)
	{
	//Do you have feathers?
	printf("Do you have feathers?: (1=yes, 0=no) ");
	scanf ("%i",&feathers);
		if (feathers == 1)
			printf("You are an Australian magpie.");
		else if (feathers == 0)
			printf("You are a shark.");
		else 
			printf("Google what you are and come back...");
	}
	
	else 
		printf("Google what you are and come back...");
	
}