/*
 * Filename: celsius_fahrenheit.c
 * Date: August 31, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 1-4. Write a program to print the
 * corresponding Celsius to Fahrenheit table.
 */
#include <stdio.h>

int main() {
	float celsius = 0, fahr;
	float lower = 0, upper = 300, step = 20;

	printf("Celsius\tFahrenheit\n");
	printf("===================\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}