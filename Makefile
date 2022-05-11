CC=g++
CFLAGS=-g -w -Wall

.PHONY: main test

all: main

main: ./src/main.cpp
	$(CC) $(CFLAGS) -o main ./src/main.cpp

test: ./test/test.cpp
	$(CC) $(CFLAGS) -o testing ./test/test.cpp
