#include "string.h"

#include <stdio.h>
#include <string.h>

void _print_status(const char *fname, int errors)
{
    if (errors)
        printf("[ \e[0;91mfail\e[0m    ] %s\n", fname);
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

int main(void)
{
    test_string_split();
    test_string_strip();

    return 0;
}
