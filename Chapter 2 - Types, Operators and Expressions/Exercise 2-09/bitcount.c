/*
 * Filename: right_rotate.c
 * Date:  April 1, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-9. In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why. Use this observation
 * to write a faster version of bitcount.
 */
#include <stdio.h> 

int bitcount(unsigned x);

int main() {
	int x = 20;
	printf("%d\n", bitcount(x));
	return 0;
}

/* 
 * First version of bitcount will traverse and check its bit one by one
 * while this second version will only check important bits
 */
int bitcount(unsigned x) {
	int b = 0;
	while (x > 0) {
		x &= (x - 1);
		b++;
	}
	return b;
}