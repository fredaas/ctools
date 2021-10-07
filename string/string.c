#include <string.h>

#include "string.h"

/* Splits 'src' at 'token' and stores the result in 'dst'
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


/* Checks if 'src' contains 'symbol'
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

/* Strips 'src' from any characters found in 'token'
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
