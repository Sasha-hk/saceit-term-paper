#include "cli.h"
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
  // Define menu options
  vector<MenuOption> baseOptions {
    {
      "make calculations",
      makeCalculations,
    },
    {
      "exit",
      exitFunction,
    }
  };

  // Create cli instance
  CLI cli = CLI(baseOptions);

  while (true) {
    cli.selectOptions();
  }

  return 0;
}
