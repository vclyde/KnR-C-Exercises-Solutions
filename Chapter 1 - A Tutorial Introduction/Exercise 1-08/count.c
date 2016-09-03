/*
 * Filename: count.c
 * Date: July 18, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-8. Write a program to count
 * blanks, tabs, and newlines.
 */
#include <stdio.h>

int main() {
	/* Counters */
	int blank_ctr = 0, tab_ctr = 0, line_ctr = 0;
	/* Character input */
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blank_ctr;

		if (c == '\t')
			++tab_ctr;

		if (c == '\n')
			++line_ctr;
	}

	printf("Tabs: %d\n", tab_ctr);
	printf("Blanks: %d\n", blank_ctr);
	printf("Lines: %d\n", line_ctr);

	return 0;
}