/*
 * Filename: inverse_bits.c
 * Date:  January 1, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-7. Write a function invert(x, p, n) that 
 * returns x with the n bits that begin at position p 
 * inverted (i.e., 1 changed into 0 and vice versa), 
 * leaving the others unchanged.
 */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void display_binary(unsigned x);

int main() {
	unsigned x = 90;
	int p = 7, n = 3;

	display_binary(x);
	display_binary(invert(x, p, n));
	printf("\n");
	
	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	int shift_pos = p + 1 - n;
	return ((~(~0 << n)) << shift_pos) ^ x;
}

/* For debugging purposes */
void display_binary(unsigned x) {
	register int t;
	for (t = 128; t > 0; t /= 2) {
		if (x & t) 
			printf("1 ");
		else 
			printf("0 ");
	}
	printf("\n");
}