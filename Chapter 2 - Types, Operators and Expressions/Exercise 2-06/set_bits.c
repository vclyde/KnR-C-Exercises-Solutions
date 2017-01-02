/*
 * Filename: set_bits.c
 * Date:  January 1, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-6. Write a function setbits(x, p, n, y) that 
 * returns x with the n bits that begin at position p set to 
 * the rightmost n bits of y, leaving the others bits unchanged.
 */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void display_binary(unsigned x);

int main() {
	unsigned x, y, result;
	int p, n;

	printf("Enter x: ");
	scanf("%u", &x);
	printf("Enter p: ");
	scanf("%d", &p);
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter y: ");
	scanf("%u", &y);

	printf("Before setting bits...\n");
	printf("x = ");
	display_binary(x);
	printf("y = ", y);
	display_binary(y);
	printf("After setting bits...\n");
	result = setbits(x, p, n, y);
	printf("%u = ", result);
	display_binary(result);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	int shift_pos = p + 1 - n;
	/* Move back to its original position after shifting to the right */
	unsigned xbits = (x >> shift_pos & ~(~0 << n)) << shift_pos; 
	/* After masking, shift to p + 1 - n */
	unsigned ybits = (y & ~(~0 << n)) << shift_pos; 
	return (~xbits & x) | ybits;
}

/* Used to display the bits of a number for debugging purposes */
void display_binary(unsigned x) {
	register int t;
	for (t = 2048; t > 0; t /= 2) {
		if (x & t) 
			printf("1 ");
		else 
			printf("0 ");
	}
	printf("\n");
}