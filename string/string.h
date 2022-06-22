#ifndef STRING_H
#define STRING_H

#include <inttypes.h>

void string_split(char dst[][32], char *src, char *token);
int string_contains(char *src, char symbol);
void string_strip(char *src, char *token);

void bit_clear(uint32_t *x, uint32_t n);
void bit_set(uint32_t *x, uint32_t n);
void bit_toggle(uint32_t *x, uint32_t n);
void bit_range_clear(uint32_t *x, uint32_t i, uint32_t n);
void bit_range_write(uint32_t *x, uint32_t i, uint32_t n, uint32_t y);
void bit_range_toggle(uint32_t *x, uint32_t i, uint32_t n);
uint32_t bit_range(uint32_t x, uint32_t a, uint32_t b);

uint32_t nbits(uint32_t b);
void print_bits(uint32_t b, uint32_t n);
uint32_t hex2bin(char *s);
void bin2char(char *s, uint32_t b);

#endif /* STRING_H */
