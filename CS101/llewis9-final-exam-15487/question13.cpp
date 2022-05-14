// Question 13 - CS101 Fall 2018 Final
#include <stdio.h>
#include <math.h>

int is_right_triangle(int a, int b, int c);

int main(void) {
	// IMPORTANT: do not modify any of the code in the main function.
	// If you do you will not receive any credit for this question.

	int side1, side2, side3;

	printf("Enter the lengths of the sides of the triangle:\n");
	scanf("%i %i %i", &side1, &side2, &side3);

	int is_right = is_right_triangle(side1, side2, side3);
	if (is_right == 0) {
		printf("Triangle is not a right triangle\n");
	} else if (is_right == 1) {
		printf("Triangle is a right triangle\n");
	} else {
		printf("Unexpected return value\n");
	}
}

// TODO: write a definition for the is_right_triangle function
int is_right_triangle(int a, int b, int c){
int hypotenuse;
int Asqrd = pow(a,2);
int Bsqrd = pow(b,2);
int Csqrd = pow(c,2);

	if((a>b && b>c) || (a>c && c>b)){
		hypotenuse = pow(a,2);
		if(hypotenuse == Bsqrd + Csqrd){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if((b>a && a>c)|| (b>c && c>a)){
		hypotenuse = pow(b,2);
		if(hypotenuse == Asqrd + Csqrd){
			return 1;
		}
		else{
			return 0;
		}
	}	
	else if((c>a && a>b) || (c>b && b>a)){
		hypotenuse =  pow(c,2);
		if(hypotenuse == Asqrd + Bsqrd){
			return 1;
		}
		else{
			return 0;
		}
	}
}