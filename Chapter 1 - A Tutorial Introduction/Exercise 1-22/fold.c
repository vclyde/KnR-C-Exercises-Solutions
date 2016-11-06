/*
 * Filename: fold.c
 * Date: September 16, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-22. Write a program to "fold" long input lines
 * into two or more shorter lines after the last non-blank character
 * that occurs before the n-th column of input. Make sure your program
 * does something intelligent with very long lines, and if there are no
 * blanks or tabs before the specified column.
 */
#include <stdio.h>
#define MAX 1000
#define COLUMN 45

/* Function prototypes */
int getline(char string[], int limit);
void fold(char string[], int size);

int main() {
	int c, length, ctr = 0;
	char string[1000];

	while ((length = getline(string, MAX)) > 0)
		fold(string, length);

	return 0;
}

/* getline: read a line into string, return length */
int getline(char string[], int limit) {
	int c; /* Variable for character input */
	int i; /* Loop increment */

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); i++)
		string[i] = c;

	if (c == '\n') {
		string[i] = c;
		++i;
	}

	string[i] = '\0';

	return i; /* Length of the string line */
}

void fold(char string[], int size) {
	int i = 0, ctr = 0;

	if (size <= COLUMN)
		printf("%s\n", string);
	else {
		printf("\n");
		for (i = 0; i < size; i++) {
			if (i != 0 && (i % (COLUMN - 1)) == 0) {
				if (string[i] != ' ' && string[i] != '\t' && string[i] != '.' && string[i - 1] != ' ') {
					putchar('-');
					putchar('\n');
				} else
				 	putchar('\n');
			}
			putchar(string[i]);
		}
		printf("\n");
	}
}