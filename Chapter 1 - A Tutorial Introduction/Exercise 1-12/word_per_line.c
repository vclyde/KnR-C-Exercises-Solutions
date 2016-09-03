/*
 * Filename: word_per_line.c
 * Date: July 20, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-12. Write a program that prints its
 * input one word per line.
 */
#include <stdio.h>

int main() {
	int c;

	while((c = getchar()) != EOF)
		if (c == ' ' || c == '\t')
			putchar('\n');
		else
			putchar(c);

	return 0;
}