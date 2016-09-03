/*
 * Filename: fahrenheit_celsius.c
 * Date: July 18, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-3. Modify the temperature conversion
 * program to print a heading above the table.
 */
#include <stdio.h>

int main() {
	float lower = 0, upper = 300, step = 20;
	float fahr = lower, celsius;

	/* Heading */
	printf("Fahrenheit\tCelsius\n");
	printf("=======================\n");
	while (fahr <= upper) {
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f\t\t%6.2f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}