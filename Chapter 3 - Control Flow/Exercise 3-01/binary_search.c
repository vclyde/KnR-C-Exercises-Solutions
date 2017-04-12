/*
 * Filename: binary_search.c
 * Date:  April 3, 2017
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 3-1. Our binary search makes two tests 
 * inside the loop, when one would suffice (at the 
 * price of more tests outside.) Write a version with
 * only one test inside the loop and measure the 
 * difference in run-time.
 */
#include <stdio.h>
#define SIZE 20

int binsearch(int x, int v[], int n);

int main() {
	int v[SIZE] = {2, 3, 5, 8, 9, 12, 20, 30, 31, 45,
					 304, 350, 448, 501, 508, 777, 799, 900, 1500, 3403};

	printf("%d\n", binsearch(10, v, SIZE));
	printf("%d\n", binsearch(448, v, SIZE));
	printf("%d\n", binsearch(777, v, SIZE));
	printf("%d\n", binsearch(0, v, SIZE));
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x > v[mid])
			low = mid + 1;
		else 
			high = mid - 1;
	}

	if (x == v[mid])
		return mid;
	else if (x == v[low])
		return low;
	else if (x == v[high])
		return high;

	return -1; /* No match */
}