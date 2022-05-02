#include "ui.h"
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

UI::UI() {}

UI::UI(vector<MenuOption> options) {
  this->menuOptions = options;
}

void UI::appendMenu(vector<MenuOption> options) {
  this->menuOptions.assign(options.end(), options.begin());
}

void UI::resetMenu(vector<MenuOption> options) {
  this->menuOptions = options;
}

void UI::selectOptions() {
  clearConsole();

  printw("Select options: \n");

  for (int i = 0; i < menuOptions.size(); i++) {
    printw(" ", i + 1, " - ", menuOptions[i].name);
  }

  int choice;

  while (true) {
    printw(" > \n");

    choice = getch();

    if (choice - 1 < menuOptions.size() && choice >= 1) {
      break;
    }
  }

  clearConsole();
  menuOptions[choice - 1].callback();

  further();
}

void UI::clearConsole() {
  clear();
}

int UI::further() {
  int input;
  input = getch();

  return 0;
}
