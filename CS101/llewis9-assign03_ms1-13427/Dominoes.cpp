		//Le Quient Lewis II
	// CS101 Assignment: 3 Milestone 1- Spring 2019
//Obtain the user input for the initial state for up to 20 dominoes where the states are represented by integers 0, 1, 2, 3
//Validate that each state is in the range 0-3 or -1.
//Print out the initial configuration using the symbols " ", "|", "/", "_" 

#include <stdio.h>
#define MAX 20

int main() {
	int pos[MAX], i=0, n=1;
	
	//Keep iterating loop until n equals the symbolic constant MAX 20
	do
	{
		//Ask for user input for the array
		printf("Position %i (0=empty, 1=upright, 2=tipping, 3=horizontal, -1=finished): ", n);
		scanf("%i", &pos[i]);
		
		//Validate input 
		if (pos[i]==-1)
		{
			break;
		}
		printf("%i", pos[i]);
		//Keep track of Inputs
		n++;
		
		//Update the index of the array
		i++;
		
	} while(n<MAX);
	
	//Check for inputs and assign/print symbols that correlate with those inputs like 0 and " "
	for(i=0;i<=n;i++)
	{	
		//If an index has a 0 stored within in it print a " "
		if(pos[i]==0)
		{
			printf(" ");
		}
		//If an index has a 1 stored within in it print a "|"
		else if(pos[i]==1)
		{
			printf("|");
		}
		
		//If an index has a 2 stored within in it print a "/"
		else if(pos[i]==2)
		{
			printf("/");
		}
		
		//If an index has a 3 stored within in it print a "_"
		else if(pos[i]==3)
		{
			printf("_");
		}
	}
	return 0;
}