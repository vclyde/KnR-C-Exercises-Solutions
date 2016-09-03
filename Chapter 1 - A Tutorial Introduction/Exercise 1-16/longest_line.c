/*
 * Filename: longest_line.c
 * Date: August 5, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-16. Revise the main routine of the
 * longest-line program so it will correctly print the
 * the length of arbitrary long input lines, and as
 * much as possible of the text.
 */
#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line length */

/* Function prototypes */
int getline(char string[], int limit);
void copy(char to[], char from[]);

int main() {
	int len; /* Current line length */
	int max = 0; /* Maximum length seen so far */
	char line[MAXLINE]; /* Current input line */
	char longest[MAXLINE]; /* Longest line saved here */

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	printf("Longest line is: " );
	if (max > 0) { /* There was a line */
		printf("%s", longest);
		printf("Length: %d", max);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char string[], int limit) {
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}