#include "common.h"

bool read_line(char *buff, FILE *fp)
{
    u32 i = 0;
    char c = fgetc(fp);
    while (c != '\n' && c != EOF)
    {
        buff[i++] = c;
        c = fgetc(fp);
    }
    buff[i] = '\0';

    return c != EOF;
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("strings.txt", "r");
    char buff[256];
    while (read_line(buff, fp))
        printf("0x%x\n", crc32_hash(buff, strlen(buff)));
}
