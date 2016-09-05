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

	while ((c = getchar()) != EOF) {
		/* If c is not new line then store to array of char*/
		if (c != '\n') {
			status = IN;
			string[i++] = c;

			/* Count the number of trailing blanks*/
			if (c == ' ' || c == '\t')
				blank++;
			else
				blank = 0;
		} else if (c == '\n' && status == IN) {
			status = OUT;
			i -= blank;
			string[i++] = '\n';
			blank = 0;
		}
	}

	string[i] = '\0';

	printf("\nOutput: \n");
	printf("%s", string);

	return 0;
}

