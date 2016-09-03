/*
 * version 1.0
 * Filename: detab.c
 * Date: August 15, 2016
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
	int length = 0;

	while ((length = getline(string, MAXLINE)) > 0) {
		printf("%d\n", length);
		length = detab(string, length);
		printf("%d\n", length);
	}

	return 0;
}

/* getline: read a line into string, return length */
int getline(char string[], int limit) {
	int c; /* For character input */
	int i; /* Loop counter increment */

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
	int i = 0, j; /* Loop counter increments */
	int ctr = 0, tab_ctr = 0;
	while (i < size) {
		if (string[i] == '\t') {
			for (j = 0; j < (SPACES_PER_TAB - tab_ctr); j++) {
				putchar(' ');
				ctr++;
			}
			tab_ctr = 0;
		} else {
			putchar(string[i]);
			ctr++;
			tab_ctr++;
		}
		++i;

		if (tab_ctr == SPACES_PER_TAB)
			tab_ctr = 0;
	}

	return ctr;
}
