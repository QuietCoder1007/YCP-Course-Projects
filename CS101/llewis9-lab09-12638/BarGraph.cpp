// TODO: add your code to this file
#include <stdio.h>

int main() {
	char answer;
	int length;

	printf("Length? ");
	scanf("%i", &length);
	for (int i=0; i< length; i++)

	{
	printf("=");
	}	

	printf("\nAnother? ");
	scanf(" %c", &answer);
	
	while ((answer == 'Y' || answer == 'y') && length > 0)
	{	
		printf("\nLength? ");
		scanf("%i", &length);

		for (int i=0; i< length; i++)
		{
			printf("=");
		}
		
		printf("\nAnother? ");
		scanf(" %c", &answer);
		if (answer == 'Y' || answer == 'y') 
		{	
			// user entered "Y" or "y"			
		} 	
		else 
		{
			// user entered some other character
			printf("Peace out sauerkraut!");
			break;
		}
	}
}