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

int main() {
	/* From the standard header files */
	printf("Ranges of different C variables from the standard header:\n");
	printf("======================================\n");
	printf("unsigned char minimum: 0\n");
	printf("unsigned char maximum: %d\n", UCHAR_MAX);
	printf("signed char minimum: %d\n", SCHAR_MIN);
	printf("signed char maximum: %d\n\n", SCHAR_MAX);

	printf("unsigned short minimum: 0\n");
	printf("unsigned short maximum: %d\n", USHRT_MAX);
	printf("signed short minimum: %d\n", SHRT_MIN);
	printf("signed short maximum: %d\n\n", SHRT_MAX);

	printf("unsigned int minimum: 0\n");
	printf("unsigned int maximum: %u\n", UINT_MAX);
	printf("signed int minimum: %d\n", INT_MIN);
	printf("signed int maximum: %d\n\n", INT_MAX);

	printf("unsigned long minimum: 0\n");
	printf("unsigned long maximum: %lu\n", ULONG_MAX);
	printf("signed long minimum: %ld\n", LONG_MIN);
	printf("signed long maximum: %ld\n\n", LONG_MAX);

	printf("unsigned long long minimum: 0\n");
	printf("unsigned long long maximum: %llu\n", ULLONG_MAX);
	printf("signed long long minimum: %lld\n", LLONG_MIN);
	printf("signed long long maximum: %lld\n\n", LLONG_MAX);

	printf("float minimum: %f\n", FLT_MIN);
	printf("float maximum: %f\n\n", FLT_MAX);

	printf("double minimum: %f\n", DBL_MIN);
	printf("double maximum: %f\n\n", DBL_MAX);

	printf("Ranges of different C variables by direct computation: \n");
	printf("======================================\n");

	return 0;
}