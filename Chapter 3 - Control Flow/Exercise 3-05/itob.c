/*
 * Filename: itob.c
 * Date:  September 6, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-5. Write the function itob(n, s, b) that converts the
 * the integer n into a base b character representation in the string s.
 * In particular, itob(n, s, 16) formats s as a hexadecimal integer in s.
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define SIZE 1000

void itob(int n, char s[], int b);

int main() {
	int n = INT_MIN;
	char s[SIZE];
	printf("%d\n", n);

	itob(n, s, 8);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}

void itob(int n, char s[], int b) {
	if (b != 2 && b != 8 && b != 10 && b != 16) {
		printf("Invalid base %d. Can only handle 2(binary), 8(octal), 10(decimal), 16(hexadecimal).\n", b);
		return;
	}

	int i = 0, sign = n, rem;
	do {
		rem = abs(n % b);
		if (b == 16) {
			if (rem < 10) 
				s[i++] = rem + '0';
			else if (rem >= 10 || rem < 16)
				s[i++] = (rem - 10) + 'A';
		} else {
			s[i++] = rem + '0';	
		}
	} while ((n /= b) != 0);

	if (sign < 0) 
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}