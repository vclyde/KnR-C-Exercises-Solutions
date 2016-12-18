/*
 * Filename: any.c
 * Date:  December 18, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-5. Write the function any(s1, s2), which returns 
 * the first location in the string s1 where any characters from 
 * the string s2 occurs, or -1 if s1 contains no characters from 
 * s2. (The standard library function strpbrk does the same job 
 * but returns a pointer to the location.)
 */
#include <stdio.h>

int any(const char s1[], const char s2[]);

int main() {
    const char s1[] = "The quick brown fox jumps over the lazy dog.";
    const char s2[] = "Hello";
    int loc = 0; 

    printf("String1: %s\n", s1);
    printf("String2: %s\n", s2);
    loc = any(s1, s2);
    printf("Found character '%c' at index %d in s1.\n", s1[loc], loc);

    return 0;
}

int any(const char s1[], const char s2[]) {
    int def = -1;
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] == s2[k])
                return i;
        }
    }

    return def;
}