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

int main() {
	unsigned x = 90, y = 7;
	int p = 6, n = 3;

	printf("Before setting bits...\n");
	printf("%u\n", x);
	printf("After setting bits...\n");
	printf("%u\n", setbits(x, p, n, y));

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