/*
 * Filename: reduce_blank.c
 * Date: July 20, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-9. Write a program to copy its input
 * to its output, replacing each string of one or
 * more blanks by a single blank.
 */
#include <stdio.h>

int main() {

	int blank_ctr = 0;
	int c;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			blank_ctr = 0;
		} else {
			blank_ctr++;
			if (blank_ctr == 1)
				putchar(c);
		}
	}

	return 0;
}