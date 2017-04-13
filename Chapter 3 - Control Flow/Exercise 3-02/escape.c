/*
 * Filename: escape.c
 * Date:  April 11, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-2. Write a function escape(s, t) that converts 
 * characters like newline and tab into visible escape sequences 
 * like \n and \t as it copies the string t to s. Use a switch.
 * Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */
#include <stdio.h>
#define SIZE 100

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main() {
	char t[] = "Hello\t\t\tworld.\n\nWelcome to C Programming.\n";
	char s[100];

	escape(s, t);
	printf("%s\n", s);
	unescape(s, s);
	printf("%s\n", s);

	return 0;
}

void escape(char s[], const char t[]) {
	int i = 0, j = 0;
	while (t[i] != '\0') {
		switch(t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
		i++;
	}
	s[j] = '\0'; /* Terminate string */
}

void unescape(char s[], const char t[]) {
	int i = 1, j = 0;
	while (t[i - 1] != '\0') {
		switch(t[i - 1]) {
			case '\\':
				if (t[i] == 'n') {
					s[j++] = '\n';
					i++;
				} else if (t[i] == 't') {
					s[j++] = '\t';
					i++;
				}
				break;
			default:
				s[j++] = t[i - 1];
				break;
		}
		i++;
	}
	s[j] = '\0'; /* Terminate string */
}