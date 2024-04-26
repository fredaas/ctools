#include <stdio.h>

#include "htable.h"

int main(void)
{
    crc32_generate(HTABLE_POLY_NORMAL);
    crc32_dump("./poly_normal.txt");

    crc32_generate(HTABLE_POLY_REVERSED);
    crc32_dump("./poly_reversed.txt");

    crc32_generate(HTABLE_POLY_RECIPROCAL);
    crc32_dump("./poly_reciprocal.txt");

    crc32_generate(HTABLE_POLY_REVERSED_RECIPROCAL);
    crc32_dump("./poly_reversed_reciprocal.txt");
}
