CC=gcc
CXX=g++

main: ./lib/cli.h ./lib/date.h ./lib/stack.h ./src/algorithm.cpp
	g++ ./src/main.cpp -o main
