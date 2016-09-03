/*
 * Filename: word_length_histogram.c
 * Date: July 27, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-13. Write a program to print a histogram of the
 * freq of words in its input. It is easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more
 * challenging.
 */
#include <stdio.h>
#define SIZE 20 /* Array size */

int main() {
	int c, i, max, space, word_length = 0; 
	int freq[SIZE];

	/* Initialize array */
	for (i = 0; i < SIZE; i++)
		freq[i] = 0;

	/* Count the length of each word */
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',') {
			if (word_length > 0) {
				++freq[word_length];
				word_length = 0;
			}
		} else
			++word_length;
	}

	/* Get the maximum frequency in the array */
	max = freq[0];
	for (i = 1; i < SIZE; i++)
		if (freq[i] > max)
			max = freq[i];


	/* Display horizontal histogram */
	printf("\nHorizontal Histogram\n");
	printf("==================================\n");
	for (i = 1; i < SIZE; i++) {
		printf("%d  ", i);
		for (int j = 0; j < freq[i]; j++)
			printf("* ");
		printf("\n");
	}

	word_length = 0;
	/* Display vertival histogram */
	printf("\nVertical Histogram\n");
	printf("==================================\n");
	for (i = max; i > 0; i--) {
		printf("%d |", i);
		for (c = 1; c < SIZE; c++) {
			space = max - freq[c];
			if ((space - word_length) > 0)
				printf("   ");
			else
				printf(" * ");
		}

		word_length++;
		printf("\n");
	}

	printf("   ============================================================\n   ");
	for (i = 1; i < SIZE; i++)
		if (i < 10)
			printf("0%d ", i);
		else
			printf("%d ", i);
		
	printf("\n");
	return 0;
}
