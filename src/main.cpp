#include "cli.h"
#include "algorithm.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makeCalculations() {
  JordanGauss algorithm = JordanGauss();

  algorithm.calculate();
}

void updateCalculations() {}

void previousCalculations() {}

void exitFunction() {
  exit(0);
}

int main() {
  vector<MenuOption> baseOptions {
    {
      "make calculations",
      makeCalculations,
    },
    {
      "update calculations",
      updateCalculations,
    },
    {
      "previous calculations",
      previousCalculations,
    },
    {
      "exit",
      exitFunction,
    }
  };

  CLI cli = CLI(baseOptions);

  while (true) {
    cli.selectOptions();
  }

  return 0;
}
