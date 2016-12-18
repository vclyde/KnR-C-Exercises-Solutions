/*
 * Filename: squeeze2.c
 * Date:  December 18, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the s2.
 */
#include <stdio.h>

void squeeze(char s1[], int ch);
void squeeze2(char s1[], char s2[]);

int main() {
    
    char s1[] = "The quick brown fox jumps over the lazy dog.!";
    char s2[] = "aeiou"; /* Characters to remove */
    
    printf("Before squeezing...\n");
    printf("String1: %s\n", s1);
    printf("String2: %s\n", s2);
    squeeze2(s1, s2);
    printf("\nAfter squeezing...\n");
    printf("%s\n", s1);

    return 0;
}

/* Original version from the book */
void squeeze(char s1[], int ch) {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] != ch) 
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

void squeeze2(char s1[], char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[k])
                s1[j++] = s1[i];  
        }
        s1[j] = '\0';
    }
}