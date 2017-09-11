/*
 * Filename: itoa3.c
 * Date:  September 5, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-6. Write a version of itoa that accepts arguments 
 * instead of two. The third argument is a minimum field width; 
 * the converted number must be padded with blanks on the left 
 * if necessary to make it wide enough.
 */
#include <stdio.h>
#define SIZE 100

// Function prototypes
void itoa(int n, char s[], int width);

int main() {
	int n = -100;
	char s[SIZE] = "\0";

	printf("%d\n", n);
	itoa(n, s, 10);
	printf("%s\n", s);
	printf("Length: %d\n", strlen(s));

	return 0;
}

void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}

void itoa(int n, char s[], int width) {
	int i = 0, sign = n;
	
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';

	while (i < width) {
		s[i++] = ' ';
	}
	s[i] = '\0';

	reverse(s);
}
