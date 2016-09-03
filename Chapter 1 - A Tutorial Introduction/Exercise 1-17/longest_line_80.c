/*
 * Filename: longest_line_80.c
 * Date: August 9, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-17. Write a program to print all input lines
 * that are longer than 80 characters.
 */
#include <stdio.h>
#define MAXLINE 1000

/* Function prototypes */
int getline(char string[], int limit);

/* Main function */
int main() {
	char string[MAXLINE];
	int length;

	while ((length = getline(string, MAXLINE)) > 0) {
		if (length > 80) {
			printf("Length: %d String: %s", length, string);
		}
	}

	return 0;
}

/* getline: read a line into string, return length */
int getline(char string[], int limit) {
	int c, i;

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
		string[i] = c;

	if (c == '\n') {
		string[i] = c;
		++i;
	}

	string[i] = '\0';

	/* Return the length of the string inputted */
	return i;
}