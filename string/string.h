#ifndef STRING_H
#define STRING_H

#include <inttypes.h>

void string_split(char dst[][32], char *src, char *token);
int string_contains(char *src, char symbol);
void string_strip(char *src, char *token);
uint32_t nbits(uint32_t b);
void print_bin(uint32_t b);
uint32_t hex2bin(char *s);
void bin2char(char *s, uint32_t b);

#endif /* STRING_H */

