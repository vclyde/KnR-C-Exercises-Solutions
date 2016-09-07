/*
 * Filename: remove.c
 * Date: September 4, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-18. Write a program to remove trailing
 * blanks and tabs from each line of input, and to
 * delete entirely blank lines.
 */
#include <stdio.h>

#define LIMIT 1000 /* String limit */
#define IN 1 /* Inside a string line */
#define OUT 0 /* Outside a string line */

int main() {
	char string[LIMIT] = {'\0'};
	int c, i = 0, blank= 0;
	int status = OUT;

	printf("\n===============\n");
	printf("Input: \n");
	printf("===============\n");

	while ((c = getchar()) != EOF) {
		/* If c is not new line then store to array of char*/
		if (c != '\n') {
			string[i++] = c;

			/* Count the number of trailing blanks*/
			if (c == ' ' || c == '\t')
				blank++;
			else {
				blank = 0;
				status = IN;
			}
		} else {
			i -= blank;
			blank = 0;
			if (status == IN) {
				status = OUT;
				string[i++] = '\n';
			}
		}
	}

	string[i] = '\0';

	printf("\n===============\n");
	printf("Output: \n");
	printf("===============\n");
	printf("%s", string);

	return 0;
}