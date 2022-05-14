// TODO: add your code to this file
#include <stdio.h>

int main() {
		//Declare doubles a & b for 
		double a, b, a1, a2, b1, b2;
	
	//Print text asking for user input
	printf("Enter first decimal value: ");
	
	//scan for user input for variable a for first decimal
	scanf("%lf",&a);
	
	//Print text asking for user input
	printf("Enter second decimal value: ");
	
	//Scan for user input for variable b for second decimal
	scanf("%lf",&b);
	
	//Addition
	a1 = a+b;
	printf("%lf + %lf = %.3lf\n",a , b, a1);
	
	//Subtraction
	a2 = a-b;
	printf("%lf - %lf = %.3lf\n",a , b, a2);
	
	//Product
	b1 = a*b;
	printf("%lf * %lf = %.3lf\n",a ,b, b1);
	
	//Quotient
	b2 = a/b;
	printf("%lf / %lf = %.3lf\n",a, b, b2);
	
	//Declare integer variables
	int c, d, c1, d1;
	
	//Print text asking for user input
	printf("Enter first integer value: ");
	
	//Scan for user input for variable c aka the First Integer
	scanf("%i", &c);
	
	//Print text asking for user input
	printf("Enter second integer value: ");
	
	//Ask for user input for variable d aka the Second Integer
	scanf("%i", &d);
	
	//Initialize c1 to equal c/d
	//Quotient
	c1 = c/d; 
	printf("%i / %i = %i\n",c , d, c1);
	
	//Initialize d1 to equal c/d
	//Modulus
	d1 = c%d;
	printf("%i %% %i = %i\n",c , d, d1);
	
	printf("Thank you for using the expensive calculator.");
}