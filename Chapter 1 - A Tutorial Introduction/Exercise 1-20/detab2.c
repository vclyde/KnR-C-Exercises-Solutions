/*
 * version 2.0
 * Filename: detab.c
 * Date: August 29, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-20. Write a program detab that replaces tabs
 * in the input with the proper number of blanks to space to
 * the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 */
#include <stdio.h>
#define MAXLINE 1000
#define SPACES_PER_TAB 8

/* Function prototypes */
int getline(char string[], int limit);
int detab(char string[], int size);

/* Main function */
int main() {
	char string[MAXLINE];
	int max = 0;

	while ((max = getline(string, MAXLINE)) > 0) {
		printf("Size: %d\n", max);
		max = detab(string, max);
		printf("Size: %d\n", max);
	}

	return 0;
}

/* getline: read a line into string, return length */
int getline(char string[], int limit) {
	int c; /* Character input variable */
	int i; /* Loop counter */

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
		string[i] = c;

	if (c == '\n') {
		string[i] = c;
		++i;
	}

	string[i] = '\0';

	return i;
}

int detab(char string[], int size) {
	int i = 0, j; /* Loop counter */
	int char_ctr = 0, spaces = 0;

	while (i < size) {
		if (string[i] == '\t') {
			/*
			   Compute the number of space char to be displayed
			   by subtracting the characters inputted to achieve
			   the same spacing as tab stop.
			 */
			spaces = SPACES_PER_TAB - (char_ctr % SPACES_PER_TAB);
			for (j = 0; j < spaces; j++) {
				putchar(' ');
				++char_ctr;
			}
		} else {
			putchar(string[i]);
			++char_ctr;
		}
		++i; /* Move to the next character in the array */
	}

	return char_ctr;
}
