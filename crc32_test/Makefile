CC=gcc
CFLAGS=-std=c99 -Wall -O0 -g -I.
OBJ := $(patsubst %.c,%.o,$(wildcard *.c))

.PHONY : clean all test dump

all : clean $(OBJ) main

dump :
	arm-linux-gnueabihf-objdump -d -M intel -S main.o

main : main.o htable.o
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ) : %.o : %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean :
	rm -rf *.o main out_*
