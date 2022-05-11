CC=g++
CFLAGS=-g -w -Wall
BUILD_DIR = build
TEST_DIR = test
BIN_DIR = ./test

.PHONY: main test

all: main

main: ./src/main.cpp
	$(CC) $(CFLAGS) -o main ./src/main.cpp

test: ./test/test.cpp
	$(CC) $(CFLAGS) -o testing ./test/test.cpp
