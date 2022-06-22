#include "string.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void _print_status(const char *fname, int errors)
{
    if (errors)
        printf("[ \e[0;91mfail\e[0m ] %s\n", fname);
    else
        printf("[ \e[0;92msuccess\e[0m ] %s\n", fname);
}

#define print_status(errors) do { \
    _print_status(__func__, errors); \
} while (0)

void test_string_split(void)
{
    char *test = "lorem,ipsum,dolor,sit,amet,consectetur,adipiscing,elit";
    char string[64][32];
    string_split(string, test, ",");
    char expected[64][32] = {
        "lorem",
        "ipsum",
        "dolor",
        "sit",
        "amet",
        "consectetur",
        "adipiscing",
        "elit" };
    int errors = 0;
    int i = 0;
    while (strcmp(string[i], "\0") != 0)
    {
        if (strcmp(string[i], expected[i]) != 0)
            errors++;
        i++;
    }

    print_status(errors);
}

void test_string_strip(void)
{
    char string[256];
    int errors = 0;

    strcpy(string, "~~\"\n");
    string_strip(string, "\"\n~");
    errors += strcmp(string, "");

    strcpy(string, "x~~\"\n");
    string_strip(string, "\"\n~");
    errors += strcmp(string, "x");

    strcpy(string, "~x~x~\"\n");
    string_strip(string, "\"\n~");
    errors += strcmp(string, "x~x");

    print_status(errors);
}

void test_hex2bin(void)
{
    int errors = 0;
    uint32_t b;

    b = hex2bin("abcd");
    errors += (b != 0xabcd);
    b = hex2bin("ffffffff");
    errors += (b != 0xffffffff);
    b = hex2bin("12340000");
    errors += (b != 0x12340000);

    print_status(errors);
}

void test_bin2char(void)
{
    int errors = 0;
    char s[32 + 1];
    bin2char(s, 0b110011);
    errors += (strcmp(s, "110011") != 0);
    bin2char(s, 0b1010101010101010101010101010101);
    errors += (strcmp(s, "1010101010101010101010101010101") != 0);
    bin2char(s, 0b11111111111111111111111111111111);
    errors += (strcmp(s, "11111111111111111111111111111111") != 0);

    print_status(errors);
}

void test_bit_set(void)
{
    int errors = 0;
    char s[32 + 1];
    uint32_t b;

    b = 0b10101010;
    bit_set(&b, 0);
    bit_set(&b, 2);
    bit_set(&b, 10);
    bin2char(s, b);
    errors += (strcmp(s, "10010101111") != 0);

    b = 0b10101010;
    bit_range_write(&b, 0, 6, 0b000001);
    bin2char(s, b);
    errors += (strcmp(s, "10000001") != 0);

    b = 0b11111111;
    bit_range_write(&b, 0, 8, 0b01111110);
    bin2char(s, b);
    errors += (strcmp(s, "1111110") != 0);

    b = 0b11111111;
    bit_range_write(&b, 4, 4, 0b1001);
    bin2char(s, b);
    errors += (strcmp(s, "10011111") != 0);

    print_status(errors);
}

int main(void)
{
    test_string_split();
    test_string_strip();
    test_bin2char();
    test_hex2bin();
    test_bit_set();

    return 0;
}
