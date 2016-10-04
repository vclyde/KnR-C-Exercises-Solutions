/*
 * Filename: reverse_string.c
 * Date: August 9, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-19. Write a function reverse(s) that
 * reverses the character string s. Use it to write
 * a program that reverses its input a line at a time.
 */
#include <stdio.h>

#define MAXLINE 1000

/* Function prototypes */
int getline(char string[], int limit);
void reverse(char string[]);

/* Main function */
int main() {
	char string[MAXLINE];
	int line_length;

	while ((line_length = getline(string, MAXLINE)) > 0)
		reverse(string);

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

/* function that reverses a string */
void reverse(char string[]) {
	int i = 0;

	/* Get the length of the string */
	while (string[i] != '\0')
		++i;

	--i; /* Ignore newline */
	/* Prints one character at a time */
	while (i >= 0)
		putchar(string[--i]);

	putchar('\n');
}