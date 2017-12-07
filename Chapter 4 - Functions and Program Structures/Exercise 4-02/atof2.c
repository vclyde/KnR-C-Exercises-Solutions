/*
 * Filename: atof2.c
 * Date:  September 15, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 4-2. Extend atof to handle scientific notation of 
 * the form 123.45e-6 where floating point number may be 
 * followed by e or E and an optionally signed exponent.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

double atof(char s[]);

int main() {

	char s[20] = "-123";
	double num = -123;
	double result = atof(s);

	/* Test case #1 */
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #2 */
	strcpy(s, "123\0");
	num = 123;
	result = atof(s);
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #3 */
	strcpy(s, "-123.05\0");
	num = -123.05;
	result = atof(s);
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #4 */
	strcpy(s, "123.05\0");
	num = 123.05;
	result = atof(s);
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #5 */
	strcpy(s, "123.05E5\0");
	num = 123.05E5;
	result = atof(s);
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #6 */
	strcpy(s, "123.05E-5\0");
	num = 123.05E-5;
	result = atof(s);
	printf("%s = %f\n", s, result);
	printf("%s = %f\n\n", s, num);

	/* Test case #7 */
	strcpy(s, "-1230.05E-5\0");
	num = -1230.05E-5;
	result = atof(s);
	printf("%s = %.10f\n", s, result);
	printf("%s = %.10f\n", s, num);

	return 0;
}

double atof(char s[]) {

	int i;
	int sign = 1, sign2 = 1; 
	double val, val2 = 0.0, power = 1.0, power2 = 1.0;

	for (i = 0; isspace(s[i]); i++) /* Remove leading spaces */
		;

	sign = (s[i] == '-') ? -1 : 1; /* Check the sign of the whole number*/
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');

	if (s[i++] == '.') {

		for (power = 1.0; isdigit(s[i]); i++) {
			val = 10.0 * val + (s[i] - '0');
			power *= 10;
		}
	}

	if (s[i] == 'e' || s[i] == 'E') {

		if (s[i + 1] == '-') {
			sign2 = -1;
			i++;
		}

		i++;
		for (val2 = 0.0; isdigit(s[i]); i++) 
			val2 = 10.0 * val2 + (s[i] - '0');
		
		for (power2 = 1.0, i = 0; i < val2; i++) 
			power2 *= 10.0;
	}

	return sign2 > 0 ? (sign * val / power) * power2 : (sign * val / power) / power2;
}