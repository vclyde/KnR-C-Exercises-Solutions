/*
 * Filename: limits.c
 * Date:  November 30, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-1. Write a program to determine the ranges of
 * char, short, int, and long variables, both signed and
 * unsigned, by printing appropriate values from standard headers 
 * and by direct computation. Harder if you compute them: determine 
 * the ranges of the various floating-point types.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

unsigned long unsigned_max(short bits);
signed long signed_max(short bits);
signed long signed_min(short bits);

int main() {
	/* From the standard header files */
	printf("Ranges of different C variables from the standard header:\n");
	printf("======================================\n");
	printf("Minimum unsigned char: 0\n");
	printf("Maximum unsigned char: %d\n", UCHAR_MAX);
	printf("Minimum signed char: %d\n", SCHAR_MIN);
	printf("Maximum signed char: %d\n\n", SCHAR_MAX);

	printf("Minimum unsigned short: 0\n");
	printf("Maximum unsigned short: %d\n", USHRT_MAX);
	printf("Minimum signed short: %d\n", SHRT_MIN);
	printf("Maximum signed short: %d\n\n", SHRT_MAX);

	printf("Minimum unsigned int: 0\n");
	printf("Maximum unsigned int: %u\n", UINT_MAX);
	printf("Minimum signed int: %d\n", INT_MIN);
	printf("Maximum signed int: %d\n\n", INT_MAX);

	printf("Minimum unsigned long: 0\n");
	printf("Maximum unsigned long: %lu\n", ULONG_MAX);
	printf("Minimum signed long: %ld\n", LONG_MIN);
	printf("Maximum signed long: %ld\n\n", LONG_MAX);

	printf("Minimum float: %f\n", FLT_MIN);
	printf("Maximum float: %f\n\n", FLT_MAX);

	printf("Minimum double: %f\n", DBL_MIN);
	printf("Maximum double: %f\n\n", DBL_MAX);

	/* By direct computation */
	printf("Ranges of different C variables by direct computation: \n");
	printf("======================================\n");
	printf("Minimum unsigned char: 0\n");
	printf("Maximum unsigned char: %d\n\n", unsigned_max(8));
	printf("Minimum signed char: %d\n", signed_min(8));
	printf("Maximum signed char: %d\n\n", signed_max(8));

	printf("Minimum unsigned short: 0\n");
	printf("Maximum unsigned short: %d\n", unsigned_max(16));
	printf("Minimum signed short: %d\n", signed_min(16));
	printf("Maximum signed short: %d\n\n", signed_max(16));

	printf("Minimum unsigned int: 0\n");
	printf("Maximum unsigned int: %u\n", unsigned_max(32));
	printf("Minimum signed int: %d\n", signed_min(32));
	printf("Maximum signed int: %d\n\n", signed_max(32));

	// long variables varies from different computer architecture
	// base on my test on different machines but I set it to 32 bit
	// by default
	printf("Minimum unsigned long: 0\n");
	printf("Maximum unsigned long: %lu\n", unsigned_max(32));
	printf("Minimum signed long: %ld\n", signed_min(32));
	printf("Maximum signed long: %ld\n\n", signed_max(32));

	printf("Minimum float: %f\n", FLT_MIN);
	printf("Maximum float: %f\n\n", pow(2, 128)); 

	printf("Minimum double: %f\n", DBL_MIN);
	printf("Maximum double: %f\n\n", pow(2, 1023.999999)); 

	// From the internet 
	printf("Ranges of different C variables by bit manipulation: \n");
	printf("======================================\n");
	printf("Minimum Signed Char: %d\n", -(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char: %d\n\n", (char)((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short: %d\n", -(short)((unsigned short)~0 >> 1) - 1);
    printf("Maximum Signed Short: %d\n\n", (short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int: %d\n", -(int)((unsigned int)~0 >> 1) - 1);
    printf("Maximum Signed Int: %d\n\n", (int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long: %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
    printf("Maximum signed Long: %ld\n\n", (long)((unsigned long)~0 >> 1));

	return 0;
}

unsigned long unsigned_max(short bits) {
	return pow(2, bits) - 1;
}

signed long signed_max(short bits) {
	return (pow(2, bits) / 2) - 1;
}

signed long signed_min(short bits) {
	return (pow(2, bits) / 2) * -1;
}