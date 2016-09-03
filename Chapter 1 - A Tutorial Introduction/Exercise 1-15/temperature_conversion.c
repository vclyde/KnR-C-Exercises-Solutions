/*
 * Filename: temperature_conversion.c
 * Date: July 26, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-15. Rewrite the temperature conversion program of
 * Section 1.2 to use a function for conversion.
 */
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

/* Function prototype */
void fahrenheit_converter();

int main() {
	fahrenheit_converter();
	return 0;
}

void fahrenheit_converter() {
	printf("Fahrenheit\tCelsius\n");
	for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d\t\t%6.1f\n", fahr, (5.0 * (fahr - 32.0) / 9.0));
}