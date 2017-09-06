/*
 * Filename: itoa2.c
 * Date:  August 31, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-4. In a two's complement number representation, 
 * our version of itoa does not handle the larget negative number,
 * that is, the value of n equal to -(2^wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the 
 * machine on which it runs.
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define SIZE 100

void itoa(int n, char s[]);

int main() {
	int n = INT_MIN;
	char s[SIZE];

	printf("Integer: %d\n", n);
	itoa(n, s);
	printf("String: %s\n", s);

	n = INT_MAX;
	printf("Integer: %d\n", n);
	itoa(n, s);
	printf("String: %s\n", s);

	return 0;
}

void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}

/*
 * No equivalent positive number when we convert the largest
 * negative number to positive so it will remain the same. 
 */
void itoa(int n, char s[]) {
	int i = 0, sign = n;
	
	do { /* generate digits in reverse order */
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0); 

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}