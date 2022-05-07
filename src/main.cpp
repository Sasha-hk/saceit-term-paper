#include "../lib/cli.h"
#include "../lib/stack.h"
#include "algorithm.cpp"

using namespace std;

// Define menu handlers
void makeCalculations();
void exitFunction();
void seePrevious();

// Solver for Jordan Gauss's algorithm
JordanGauss algorithm = JordanGauss();

// Menu handlers
void makeCalculations() {
  algorithm.calculate();
}

void exitFunction() {
  exit(0);
}

void seePrevious() {
  algorithm.seePrevious(algorithm.popStory());
}

int main() {
  vector<MenuOption> extendedOptions = {
    {
      "make calculations",
      makeCalculations,
    },
    {
      "see previous calculation",
      seePrevious,
    },
    {
      "exit",
      exitFunction,
    }
  };

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

  while (true) {
    if (algorithm.dumpSize() > 0) {
      cli.selectOptions(extendedOptions);
    }
    else {
      cli.selectOptions();
    }
  }

  return 0;
}
