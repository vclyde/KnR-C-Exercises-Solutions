/*
 * Filename: lower_case.c
 * Date:  April 2, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-10. Rewrite the function lower, which converts
 * upper case letters to lower case, with a conditional expression
 * instead of if-else.
 */
#include <stdio.h>

int lower(int c);

int main() {
	char letter = 'A';
	printf("%c\n", lower(letter));
	return 0;
}

int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}