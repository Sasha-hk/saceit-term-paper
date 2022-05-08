CC=g++
CFLAGS=-g -w -Wall

main: main.o date.o stack.o cli.o algorithm.o
	$(CC) $(CFLAGS) -o main main.o date.o stack.o cli.o algorithm.o

# test: ./test/test.cpp date.o stack.o cli.o
# 	$(CC) $(CFLAGS) -o main main.o

main.o: ./src/main.cpp
	$(CC) $(CFLAGS) -c ./src/main.cpp

algorithm.o: ./src/algorithm.cpp
	$(CC) $(CFLAGS) -c ./src/algorithm.cpp

date.o: ./include/date.hpp
	$(CC) $(CFLAGS) -c ./include/date.hpp

stack.o: ./include/stack.hpp
	$(CC) $(CFLAGS) -c ./include/stack.hpp

cli.o: ./include/cli.hpp
	$(CC) $(CFLAGS) -c ./include/cli.hpp
