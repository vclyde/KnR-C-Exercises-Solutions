/*
 * Filename: verify.c
 * Date: July 18, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-6. Verify that the expression
 * getchar() != EOF is 0 or 1.
 */
#include <stdio.h>

int main() {
	int c;
	int i;

	while (i = ((c = getchar()) != EOF))
		printf("%d\n", i);

	/* Display the value of i after exiting the loop */
	printf("%d\n", i);

	return 0;
}

