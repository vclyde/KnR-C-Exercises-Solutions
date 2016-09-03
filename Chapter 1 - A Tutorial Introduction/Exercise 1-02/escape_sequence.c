/*
 * Filename: escape_sequence.c
 * Date: August 31, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-2. Experiment to find out what happens
 * when print's argument string contains \c, where
 * c is some character not listed above.
 */
 #include <stdio.h>

 int main() {
	 printf("\n"); /* newline */
	 printf("\t"); /* horizontal tab */
	 printf("\v"); /* vertical tab */
	 printf("\b"); /* backspace */
	 printf("\r"); /* carriage return */
	 printf("\f"); /* formfeed */
	 printf("\a"); /* audible alert */
	 printf("\\"); /* backslash */
	 printf("\?"); /* question mark */
	 printf("\'"); /* single quote */
	 printf("\""); /* double quote */

	 printf("\c"); /* Not recognized character escape sequence */
	 /* Compiler will throw an error */
	 return 0;
 }