/*
 * Filename: loop.c
 * Date:  December 3, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-2. Write a loop equivalent to the 
 * for loop above (for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)) 
 * without using && or ||.
 */
#include <stdio.h>
#define LIMIT 1024

int main() {
	char s[LIMIT];
	int c, i, lim = LIMIT;

	for (i = 0; i < lim-1; ++i) {
		c = getchar();
		if (c == '\n')
			lim = 0; // Exit loop
		else if (c == EOF)
			lim = 0; // Exit loop
		else
			s[i] = c;
	}

	s[--i] = '\0';
	printf("%s\n", s);
	return 0;
}