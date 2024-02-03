CC = gcc
CFLAGS = -D_XOPEN_SOURCE=700 -Og -g -std=c11 -Wall -pedantic -fsanitize=address

all: split

split: main.o split.o
    $(CC) $(CFLAGS) -o split main.o split.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

split.o: split.c split.h
    $(CC) $(CFLAGS) -c split.c

clean:
    rm -f split main.o split.o

.PHONY: all clean
