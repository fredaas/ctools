#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>

#include "string.h"

/**
 * Splits 'src' at 'token' and stores the result in 'dst'
 *
 * 'dst' max string length is 32.
 *
 * 'src' max string length is 512.
 */
void string_split(char dst[][32], char *src, char *token)
{
    /* Make sure we don't change the 'src' pointer */
    char string[512];
    strcpy(string, src);
    int i = 0;
    char *chunk = strtok(string, token);
    while (chunk != NULL)
    {
        strcpy(dst[i++], chunk);
        chunk = strtok(NULL, token);
    }
    strcpy(dst[i], "\0");
}


/**
 * Checks if 'src' contains 'symbol'
 *
 * Returns 1 if true, 0 otherwise.
 */
int string_contains(char *src, char symbol)
{
    int i = 0;
    char c;
    while ((c = src[i++]) != '\0')
    {
        if (c == symbol)
            return 1;
    }
    return 0;
}

/**
 * Strips 'src' from any characters found in 'token'
 */
void string_strip(char *src, char *token)
{
    int size = strlen(src);
    if (!size)
        return;
    int j = size - 1;
    while (j >= 0 && string_contains(token, src[j]))
        j--;
    src[j + 1] = '\0';
    int i = 0;
    while (i < j && string_contains(token, src[i]))
        i++;
    strcpy(src, src + i);
}

/**
 * Counts the number of bits in 'b'
 */
uint32_t nbits(uint32_t b)
{
    uint32_t count = 0;
    while ((b >>= 1) > 0)
        count++;
    return count + 1;
}


/**
 * Prints the binary representation of 'b'
 */
void print_bin(uint32_t b)
{
    int n = nbits(b);
    while (n > 0)
        printf("%d", (b >> --n) & 1);
    printf("\n");
}

/**
 * Returns the 4-bit binary representation of the hex character 'c', or -1 if
 * the 'c' is not a valid hex character
 */
int lut(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0') & 0xf;
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10) & 0xf;
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10) & 0xf;
    return -1;
}

/**
 * Returns the binary representation of the hex string 's'
 */
uint32_t hex2bin(char *s)
{
    int k, i = 0;
    uint32_t acc = 0;
    while ((k = lut(s[i++])) != -1)
        acc = (acc << 4) + k;
    return acc;
}

/**
 * Returns the binary string representation of 'b'
 */
void bin2char(char *s, uint32_t b)
{
    int i = 0, n = nbits(b);
    while (n > 0)
        s[i++] = (b >> --n) & 1 ? '1' : '0';
    s[i] = '\0';
}
