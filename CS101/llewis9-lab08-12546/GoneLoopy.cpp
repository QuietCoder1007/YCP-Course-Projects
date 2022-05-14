#include<stdio.h>

int main(void) {
  // TODO: add your code for Part 1 here
    int totNum, num, count;
	float average;
	
	printf("Enter a value: ");
	scanf("%i", &num);
	
	while (num == -1)
	{	
		printf("No values were input. Please try again: ");
		scanf("%i", &num);
	}
	while (num != -1)
	{
		totNum += num; 		
		count++;
		printf("Enter a value: ");
		scanf("%i", &num);
	}		
		average = totNum/count;
		printf("The average of the %i values is %.2f", count, average);	

// TODO: add your code for Part 2 here
	float dollars, centsG, centsH;
	int Day;
	
	printf("\nHow much money do you want (in dollars): ");
	scanf("%f", &dollars);
	
	centsG = 0.01;
		while (centsH < dollars)
	{	
		Day++;
		centsH += centsG;
		printf("\nDay %i: Given $%.2f, you now have $%.2f", Day, centsG, centsH);
		centsG *= 2; 
	}
		printf("\nOn day %i, you will have met (or exceeded) your request for $%.2f with a total of $%.2f", Day, dollars, centsH);   
}


