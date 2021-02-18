CC=gcc
CFLAGS=-std=c99 -Wall -O0 -I/. -g -Wno-unused-variable

OBJ=htable.o

CFLAGS+=-Wno-unused-result

all : clean utest

utest : utest.c htable.o
	$(CC) -o $@ $^ $(CFLAGS)

crc32_generate : crc32_generate.c htable.o
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ) : %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

memcheck :
	valgrind --leak-check=yes ./utest

clean :
	rm -f utest crc32_generate *.txt *.o
