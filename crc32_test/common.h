#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef int s32;
typedef long s64;
typedef float f32;
typedef double f64;

u32 crc32_hash(void *key, size_t size);

#endif /* COMMON_H */
