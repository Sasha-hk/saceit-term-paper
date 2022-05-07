#include "../lib/cli.h"
#include "../lib/stack.h"
#include "algorithm.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

JordanGauss algorithm = JordanGauss();

void makeCalculations() {
  algorithm.calculate();
}

void exitFunction() {
  exit(0);
}

int main() {
  // Create CLI instance
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

  while (true) {
    cli.selectOptions();
  }

  return 0;
}
