CC=g++
CFLAGS=-g -w -Wall

.PHONY: main test

all: main

main: ./src/main.cpp
	$(CC) $(CFLAGS) -o main ./src/main.cpp

test: ./tests/test.cpp
	$(CC) $(CFLAGS) -o test ./tests/test.cpp
