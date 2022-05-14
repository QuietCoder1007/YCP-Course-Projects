// Question 14 - CS101 Fall 2018 Final
#include <stdio.h>

#define MAX 100

int check_palindrome(int numbers[], int n);

// IMPORTANT: do not modify the main function except where indicated
int main(void) {

	int count;
	int seq[MAX];

	printf("How many numbers? ");
	scanf("%i", &count);

	printf("Enter a sequence of %i integers:\n", count);
	for (int i = 0; i < count; i++) {
		scanf("%i", &seq[i]);
	}

	int is_pal;
	
	// TODO: write a function call to check_palindrome
	is_pal=check_palindrome(seq, count);
	
	if (is_pal == 0) {
		printf("Sequence is not a palindrome\n");
	} else if (is_pal == 1) {
		printf("Sequence is a palindrome\n");
	} else {
		printf("Unexpected return value\n");
	}
	return 0;
}

// TODO: write a definition of the check_palindrome function
int check_palindrome(int numbers[], int n){
	int a, fin=n-1;
	for(int i=0; i<n; i++){
		int min = numbers[i];
		int max = numbers[fin-i];
		
		if(min != max){
			a = 0;
			break;
		}
		else{
			a = 1;
		}
	}
	return a;
}