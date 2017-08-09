/*
 * Filename: expand.c
 * Date:  August 8, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-3. Write a function expand(s1, s2) that
 * expands shorthand notations like a-z in the string 
 * s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be 
 * prepared to handle cases like a-b-c and a-z0-9 and 
 * -a-z. Arrange that a leading or trailing - is taken 
 * literally.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

void expand(char s1[], char s2[]);

int main() {
	char result[SIZE];
	expand("A-z", result);
	printf("Result: %s\n", result);

	expand("a-z", result);
	printf("Result: %s\n", result);

	expand("a-b-c", result);
	printf("Result: %s\n", result);

	expand("$a-zA-Z0-9-", result);
	printf("Result: %s\n", result);

	expand("-A-Z", result);
	printf("Result: %s\n", result);

	expand("-a65f6d6sfa6sfzjkjkjkkk", result);
	printf("Result: %s\n", result);
	return 0;
}

void expand(char s1[], char s2[]) {
	int length = strlen(s1);
	int start = -1, end = -1;
	int prev = -1, curr = -1, next = -1;
	int i, j = 0;

	prev = length > 0 ? s1[0] : -1;
	for (i = 1; i < length; i++) {
		curr = s1[i];
		next = (i + 1) <= length ? s1[i + 1] : -1;
		if (curr == '-' && prev < next) {
			start = prev;
			end = next;

			if (((isalpha(prev) && isalpha(next)) && ((islower(prev) && islower(next)) || (isupper(prev) && isupper(next)))) 
				|| (isdigit(prev) && isdigit(next))) {
				if (j > 0 && s2[j - 1] == prev) {
					start++;
				}

				while (start <= end) {
					s2[j++] = start;
					start++;
				}
			}

			/* Reset */
			start = -1;
			end = -1;
		}
		prev = curr;
	}
	s2[j] = '\0';
}