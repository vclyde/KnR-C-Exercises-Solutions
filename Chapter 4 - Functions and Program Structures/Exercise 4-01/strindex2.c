/*
 * Filename: strindex2.c
 * Date:  September 13, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 4-1. Write the function strindex(s, t) which returns the 
 * position of the rightmost occurence of t in s, or -1 if there
 * is none.
 */
#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int strindex(char s[], char t[]);

int main() {

	char pattern[] = "ould";
	char line[MAXLINE];
	int index = 0;

	while (getline(line, MAXLINE) > 0) {
		if ((index = strindex(line, pattern)) >= 0) {
			printf("Index: %d, Line: %s", index, line);
		}
	}

	return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
	int c, i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = strlen(s) - 1; i > 0; i--) {
		for (j = i, k = strlen(t) - 1; k > 0 && s[j] == t[k]; j--, k--)
			;

		if (k <= 0)
			return j;
	}

	return -1;
}