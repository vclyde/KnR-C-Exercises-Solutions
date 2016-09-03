/*
 * Filename: fahrenheit_celsius_rev.c
 * Date: August 31, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-5. Modify the temperature conversion
 * program to print the table in reverse order, that
 * is, from 300 degrees to 0.
 */
#include <stdio.h>

int main() {
	float lower = 0, upper = 300, step = 20;
	float fahr = upper, celsius;

	/* Heading */
	printf("Fahrenheit\tCelsius\n");
	printf("=======================\n");
	while (fahr > upper) {
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f\t\t%6.2f\n", fahr, celsius);
		fahr -= step;
	}
	return 0;
}