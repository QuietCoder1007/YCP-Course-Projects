// TODO: add your code to this file
#include <stdio.h>
int main (){
	int rows, col, i, j;
	char speChar;
	
	printf("Number of rows: ");
	scanf("%i", &rows);
	
	printf("Number of columns: ");
	scanf("%i", &col);
	
	printf("Special Character: ");
	scanf(" %c", &speChar);
	
	i = 0;
	
	while (i < rows)
	{	i++;
		printf("\n");
		j=0;
		
		while (j < col)
		{	j++;
			if ((j == 2 && i == 2)  || (i == rows - 1 && j == col - 1) || (j == col - 1 && i == 2)|| (j == 2 && i == rows - 1))
			{
				printf("%c", speChar);
			}	
			else
			{
				printf(".");
			}	
		}
	}	
}