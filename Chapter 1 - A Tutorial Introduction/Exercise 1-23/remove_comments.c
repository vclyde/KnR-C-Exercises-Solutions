/*
 * Filename: remove_comments.c
 * Date:  November 6, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-23. Write a program to remove all comments
 * from a C program. Don't forget to handle quoted strings
 * and character constants properly. C comments don't nest.
 */
#include <stdio.h>

#define LIMIT 10240
#define OUT 0
#define SINGLE_COMMENT 1
#define MULTI_COMMENT 2
#define SINGLE_QUOTE 3
#define DOUBLE_QUOTE 4

/* Function prototype */
void remove_comments(char ccode[]);

int main() {
	int ch, i = 0;
	char code[LIMIT];

	/* Input string */
	while ((ch = getchar()) != EOF) 
		code[i++] = ch;

	code[i++] = '\n';
	code[i] = '\0';

	remove_comments(code);
	
	printf("\n====================\n");
	printf("New C code:\n");
	printf("====================\n");
	printf("%s", code);
	
	return 0;
}

/* Remove comments from a c program */
void remove_comments(char ccode[]) {
	int i = 1, j = 0, k = 0, i_temp = i; 
	int prev_ch = ccode[i - 1], status = OUT, comment_ctr = 0, comment_closing = 0;
	char code[LIMIT];
	
	while (prev_ch != '\0') {
		
		/* Checks if single line and multi line comments are present */
		if (status == OUT && (prev_ch == '/' && ccode[i] == '*')) {
			status = MULTI_COMMENT;
			comment_ctr++;
		} else if (status == OUT && (prev_ch == '/' && ccode[i] == '/')) {
			status = SINGLE_COMMENT;
			comment_ctr++;
		} else if ((prev_ch == '*' && ccode[i] == '/') && status == MULTI_COMMENT) {
			status = OUT;
			comment_closing = 2;
		} else if (prev_ch == '\n' && status == SINGLE_COMMENT) {
			status = OUT;
			comment_closing = 1;
		}

		/* Handles chars and strings */
		if (status == OUT && prev_ch == '\'') {
			status = SINGLE_QUOTE;
		} else if (status == OUT && prev_ch == '"') {
			status = DOUBLE_QUOTE;
		} else if (status == SINGLE_QUOTE) {
			if (prev_ch == '\\') {
				if (ccode[i] == '\'' || ccode[i] == '\\') {
					i++;
				}
			} else if (prev_ch == '\'') {
				status = OUT;
			}
		} else if (status == DOUBLE_QUOTE) {
			if (prev_ch == '\\') {
				if (ccode[i] == '"' || ccode[i] == '\\') {
					i++;
				}
			} else if (prev_ch == '"') {
				status = OUT;
			}
		}

		/* Write to new array without the comments */
		if (status != MULTI_COMMENT && status != SINGLE_COMMENT && comment_closing <= 0) 
			code[j++] = prev_ch;

		if (comment_closing > 0)
			comment_closing--;

		if (i_temp != i)
			code[j++] = ccode[i - 1];
		
		prev_ch = ccode[i];
		i++;
		i_temp = i;
	}

	/* Copy back to ccode */
	i = 0;
	while(code[i] != '\0') {
		ccode[i] = code[i];
		i++;
	}
	ccode[i] = '\0';
	
	/* Use to verify the number of comments that exist */
	printf("\nNumber of comment(s): %d\n", comment_ctr);
}