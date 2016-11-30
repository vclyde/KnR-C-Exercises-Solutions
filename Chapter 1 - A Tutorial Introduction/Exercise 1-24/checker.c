/*
 * Filename: checker.c
 * Date:  November 6, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-24. Write a program to check a C program
 * for rudimentary syntax errors like unmatched parentheses, 
 * brackets and braces. Don't forget about quotes, both 
 * single and double, escape sequences, and comments. 
 * (This program is hard if you do it in full generality.)
 */
#include <stdio.h>

#define LIMIT 10240
#define OUT 0 
#define SINGLE_COMMENT 1
#define MULTI_COMMENT 2
#define SINGLE_QUOTE 3
#define DOUBLE_QUOTE 4

int is_opening_bracket(char ch);
int is_closing_bracket(char ch);
int is_bracket_pair(char open, char close);
void checker(char ccode[]);

int main() {
	int ch, i = 0;
	char ccode[LIMIT];

	while ((ch = getchar()) != EOF) 
		ccode[i++] = ch;

	ccode[i++] = '\n';
	ccode[i] = '\0';
	checker(ccode);

	return 0;
}

int is_opening_bracket(char ch) {
	return ch == '{' || ch == '(' || ch == '[';
}

int is_closing_bracket(char ch) {
	return ch == '}' || ch == ')' || ch == ']';
}

int is_bracket_pair(char open, char close) {
	return (open == '{' && close == '}') || 
			(open == '(' && close == ')') || 
			(open == '[' && close == ']');
}

void checker(char ccode[]) {
	int status = OUT;
	int ctr = 0, i = 1, prev_ch = ccode[i - 1];
	int bracket_stack[LIMIT] = { -1 };

	while (prev_ch != '\0') {
		/* Handles square, curve and curly brackets */  
		if (status == OUT && is_opening_bracket(prev_ch)) {
			bracket_stack[ctr++] = prev_ch;
		} else if (status == OUT && is_closing_bracket(prev_ch)) {
			if (ctr == 0) {
				bracket_stack[ctr++] = prev_ch;
			} else {
				if (is_bracket_pair(bracket_stack[ctr - 1], prev_ch))
					bracket_stack[ctr--] = ' ';
				else 
					bracket_stack[ctr++] = prev_ch;
			}
		} 

		/* Checks single and multi-line comments */ 
		if (status == OUT && (prev_ch == '/' && ccode[i] == '*')) 
			status = MULTI_COMMENT;
		else if (status == OUT && (prev_ch == '/' && ccode[i] == '/'))
			status = SINGLE_COMMENT;
		else if ((prev_ch == '*' && ccode[i] == '/') && status == MULTI_COMMENT)
			status = OUT;
		else if (prev_ch == '\n' && status == SINGLE_COMMENT)
			status = OUT;

		/* Checks single and double quoted strings */
		if (status == OUT && prev_ch == '\'') {
			status = SINGLE_QUOTE;
		} else if (status == OUT && prev_ch == '"') {
			status = DOUBLE_QUOTE;
		} else if (status == SINGLE_QUOTE) {
			if (prev_ch == '\\') {
				if (ccode[i] == '\'' || 
					ccode[i] == '\\' || 
					ccode[i] == 'a' ||
					ccode[i] == 'b' ||
					ccode[i] == 'f' ||
					ccode[i] == 'n' ||
					ccode[i] == 'r' ||
					ccode[i] == 't' ||
					ccode[i] == 'v') {
					i++;
				} else {
					printf("Syntax error! -> \\ found in string should escape instead\n");
				}
			} else if (prev_ch == '\'') {
				status = OUT;
			}
		} else if (status == DOUBLE_QUOTE) {
			if (prev_ch == '\\') {
				if (ccode[i] == '\'' || 
					ccode[i] == '\\' || 
					ccode[i] == 'a' ||
					ccode[i] == 'b' ||
					ccode[i] == 'f' ||
					ccode[i] == 'n' ||
					ccode[i] == 'r' ||
					ccode[i] == 't' ||
					ccode[i] == 'v') {
					i++;
				} else {
					printf("Syntax error! -> \\ found in string should escape instead\n");
				}
			} else if (prev_ch == '"') {
				status = OUT;
			}
		}

		prev_ch = ccode[i];
		i++;
	}

	if (ctr > 0)
		printf("Syntax error! -> Unmatched brackets\n");

	if (status == MULTI_COMMENT)
		printf("Syntax error! -> Multi-line comment not close\n");
	else if (status == SINGLE_QUOTE)
		printf("Syntax error! -> Single quote character not close\n");
	else if (status == DOUBLE_QUOTE)
		printf("Syntax error! -> Double quote character not close\n");
}