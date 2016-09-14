/*
 * Filename: entab.c
 * Date: September 14, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-21. Write a program entab that replaces strings
 * of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing. Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach
 * a tab stop, which should be given preference?
 */
#include <stdio.h>
#define MAXLINE 1000
#define TAB_STOP 8

/* Function prototypes */
int getline(char string[], int limit);
int entab(char string[], int size);

/* Main function */
int main() {
	char string[MAXLINE];
	int length;

	while ((length = getline(string, MAXLINE)) > 0) {
		printf("Size: %d\n", length);
		length = entab(string, length);
		printf("Size: %d\n", length);
	}

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

int entab(char string[], int size) {
	int i = 0, j;
	int space_ctr = 0, size_ctr = 0, tab_ctr = 0;

	while (i < size) {
		tab_ctr++;
		if (string[i] != ' ') {
			if (space_ctr > 0) {
				for (j = 0; j < space_ctr; j++) {
					putchar(' ');
					size_ctr++;
				}
				space_ctr = 0; /* Reset ctr */
			}

			putchar(string[i]);
			size_ctr++;
		} else {
			space_ctr++;
			if (space_ctr > 0 && tab_ctr == TAB_STOP) {
				putchar('\t');
				size_ctr++;
				/* Reset ctrs */
				tab_ctr = 0;
				space_ctr = 0;
			}
		}

		i++; /* Move to the next character */
	}

	return size_ctr;
}