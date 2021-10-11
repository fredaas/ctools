CFLAGS=-std=c99 -Wall -O2 -Wall
CC=gcc

all : clean utest

utest : utest.c queue.c
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm -f string
