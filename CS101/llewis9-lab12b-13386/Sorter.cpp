// TODO: add your code to this file
#include <stdio.h>

int main()
{
	double A[10];
	int temp=0;
		
		for(int i=0;i<10;i++)
		{
			printf("Enter value %i: ",i+1);
			scanf("%lf", &A[i]);
			
			if (A[i]<0)
			{
				break;
			}
		n+=i;
		}
		
		for(int i=0; i<10;i++)
		{
			for(int j=-1; j<=i;j++)
			

				if (A[i]<A[j+1])
				{
					temp = A[i];
					A[i] = A[j+1];
					A[j+1] = temp;
				}
		}
		
		printf("The values from smallest to largest are: \n");
		for(int i=0; i<10;i++)
		{
			printf("%.1lf ", A[i]);
		}	
		
		
		
}
		