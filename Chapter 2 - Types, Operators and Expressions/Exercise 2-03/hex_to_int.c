/*
 * Filename: hex_to_int.c
 * Date:  December 8, 2016
 * Author: Clyde M. Velasquez
 *
 * The C Programming Language
 * by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Exercise 2-3. Write the function htoi(s), which converts a 
 * string of hexadecimal digits (including an optional 0x or 0X)
 * into its equivalent integer value. The allowable digits are
 * 0 through 9, a through f, and A through F.
 */
#include <stdio.h>
#include <math.h>

#define HEX_BASE 16
#define LIMIT 10

/* Function prototype */
int htoi(char hex_string[]);

int main() {
    char ch, string[LIMIT];
    int i = 0; 

    while ((ch = getchar()) != '\n' && i < LIMIT) 
        string[i++] = ch;
    
    string[i] = '\0';
    printf("%s -> %d\n", string, htoi(string));

    return 0;
}

int htoi(char hex_string[]) {
    int length, i = 0, start = 0, result = 0;
    char hex;

    /* Count the length of the string */
    while (hex_string[i] != '\0')
        i++;
    
    if (i > 0) {
        /* Ignore 0x or 0X */
        if (hex_string[0] == '0' && (hex_string[1] == 'x' || hex_string[1] == 'X')) 
            start = 2; 

        length = (i - start);

        while (start < i) {
            hex = hex_string[start];

            if (hex >= '0' && hex <= '9')
                result += ((hex - '0') * pow(HEX_BASE, --length));
            else if (hex >= 'a' && hex <= 'f')
                result += (((hex - 'a') + 10) * pow(HEX_BASE, --length));
            else if (hex >= 'A' && hex <= 'F')
                result += (((hex - 'A') + 10) * pow(HEX_BASE, --length));
            else {
                printf("Invalid character -> %c\n", hex);
                return -1;
            }

            start++;
        }
    }

    return result;
}