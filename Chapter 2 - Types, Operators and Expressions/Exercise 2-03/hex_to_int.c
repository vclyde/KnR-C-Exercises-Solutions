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

#define HEX_BASE 16
#define LIMIT 10

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
    int start = 0, result = 0;
    char hex;

    /* Ignore 0x or 0X */
    if (hex_string[0] == '0' && (hex_string[1] == 'x' || hex_string[1] == 'X')) 
        start = 2; 

    while ((hex = hex_string[start]) != '\0' ) {
        result *= HEX_BASE;

        if (hex >= '0' && hex <= '9')
            result += (hex - '0');
        else if (hex >= 'a' && hex <= 'f')
            result += ((hex - 'a') + 10);
        else if (hex >= 'A' && hex <= 'F')
            result += ((hex - 'A') + 10);
        else {
            printf("Invalid character -> %c\n", hex);
            return -1;
        }

        start++;
    }
    

    return result;
}