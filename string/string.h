#ifndef STRING_H
#define STRING_H

void string_split(char dst[][32], char *src, char *token);
int string_contains(char *src, char symbol);
void string_strip(char *src, char *token);

#endif /* STRING_H */