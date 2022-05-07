#include "../lib/cli.h"
#include "../lib/stack.h"
#include "algorithm.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define menu handlers
void makeCalculations();
void exitFunction();

// Solver for Jordan Gauss's algorithm
JordanGauss algorithm = JordanGauss();

// CLI instance
CLI cli = CLI({
  {
    "make calculations",
    makeCalculations,
  },
  {
    "exit",
    exitFunction,
  }
});

// Menu handlers
void makeCalculations() {
  algorithm.calculate();
}

void exitFunction() {
  exit(0);
}

int main() {

  while (true) {
    cli.selectOptions();
  }

  return 0;
}
