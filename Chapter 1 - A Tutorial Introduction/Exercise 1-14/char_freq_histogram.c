/*
 * Filename: char_freq_histogram.c
 * Date: September 1, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-14. Write a program to print a histogram of the
 * frequencies of differenct characters in its input.
 */
#include <stdio.h>
#define ARRAY_SIZE 127
#define START 32

int main() {
	int c; /* For character input */
	int sizes[ARRAY_SIZE];
	int i;

	/* Initialize array */
	for (i = 0; i < ARRAY_SIZE; i++)
		sizes[i] = 0;

	/* Count the length of each character */
	while ((c = getchar()) != EOF)
		sizes[c]++;

	/* Display histogram */
	for (i = START; i < ARRAY_SIZE; i++) {
		printf("%c - ", i);
		for (c = 0; c < sizes[i]; c++)
			printf("* ");
		printf("\n");
	}

	return 0;
}