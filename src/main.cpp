#include "ui.cpp"
#include "algorithm.cpp"
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include <iostream>

using namespace std;

void makeCalculations() {
  JordanGauss algorithm = JordanGauss();

  algorithm.calculate();
}

void updateCalculations() {}

void previousCalculations() {}

void exitFunction() {
  refresh();
  endwin();
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

  UI cli = UI(baseOptions);

  // Setup ncurses
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  while (true) {
    cli.selectOptions();
  }

  refresh();
  endwin();

  return 0;
}
