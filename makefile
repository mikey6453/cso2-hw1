CC = clang
CFLAGS = -g -Og -std=c11 -Wall -pedantic -fsanitize=address
LDFLAGS = -Wall -fsanitize=address

SRC = split.c main.c
OBJ = $(SRC:.c = .o)
EXEC = split


split: split.o main.o
    $(CC) $(LDFLAGS) -o $@ split.o main.o

main.o: main.c split.h
    $(CC) $(CFLAGS) -o $@ -c $<

split.o: split.c split.h
    $(CC) $(CLFAGS) -o $@ -c $<

clean:
    rm split.o main.o split