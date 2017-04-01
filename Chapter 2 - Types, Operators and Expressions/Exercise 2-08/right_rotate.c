/*
 * Filename: right_rotate.c
 * Date:  December 28, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-8. Write a function rightrot(x, n) that returns 
 * the value of the integer x rotated to the right by n positions.
 */
#include <stdio.h>

unsigned rightrot(int x, int n);
void display_binary(unsigned x);

int main() {
	int x = 1000, n = 51, rotate_val = 0;

	printf("Number: %d\n", x);
	display_binary(x);

	rotate_val = rightrot(x, n);
	printf("\nNumber: %d\n", rotate_val);
	display_binary(rotate_val);

	return 0;
}

unsigned rightrot(int x, int n) {
	int bits = 0, num = x;
	/* Count the number of bits first */
	while (num > 0) {
		bits++;
		num /= 2;
	}
	n %= bits;

	return ((x & ~(~0 << n)) << (bits - n)) | (x >> n);
}

/* For debugging purposes */
void display_binary(unsigned x) {
	register int t;
	for (t = 1024; t > 0; t /= 2) {
		if (x & t) 
			printf("1 ");
		else 
			printf("0 ");
	}
	printf("\n");
}