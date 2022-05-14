// Question 15 - CS101 Fall 2018 Final
#include <stdio.h>

// Important: don't modify the definition of the
// struct Complex data type
struct Complex {
	// Fields for the values of the real and imaginary
	// components of a complex number
	double real, imag;
};

// TODO: add a prototype for the complex_mul function
struct Complex complex_mul(struct Complex *a , struct Complex *b);

// IMPORTANT: do not modify the main function in any way
int main(void) {
	struct Complex c1, c2;

	printf("First complex number (real, imag): ");
	scanf("%lf %lf", &c1.real, &c1.imag);
	printf("Second complex number (real, imag): ");
	scanf("%lf %lf", &c2.real, &c2.imag);

	struct Complex product;
	product = complex_mul(&c1, &c2);

	printf("Product is (%lf + %lfi)\n", product.real, product.imag);

	return 0;
}

// TODO: add a definition for the complex_mul function
struct Complex complex_mul(struct Complex *a , struct Complex *b){
	struct Complex total;
	total.real = (a->real*b->real) - (a->imag*b->imag);
	total.imag = (b->real*a->imag) + (b->imag*a->real);

	return total;
}
