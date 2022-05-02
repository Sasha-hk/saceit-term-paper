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

void UI::showMenu(int active) {
  noecho();
  clear();

  printw("Select options: \n");

  for (int i = 0; i < menuOptions.size(); i++) {
    if (i == active) {
      printw(" > ");
    } else {
      printw("   ");
    }

    printw(menuOptions[i].name.c_str());
    printw("\n");
  }
}

void UI::selectOptions() {
  int input;
  int choice = 0;

  while (true) {
    showMenu(choice);

    input = getch();
    printw(to_string(input).c_str());
    printw("\n");

    if (input == 10) {
      break;
    }

    switch (input) {
      case 259: {
        if (choice - 1 <= menuOptions.size()) {
          choice -= 1;
        }

        break;
      }
      case 258: {
        if (choice + 1 <= menuOptions.size()) {
          choice += 1;
        }

        break;
      }
      case 106: {
        if (choice + 1 <= menuOptions.size()) {
          choice += 1;
        }

        break;
      }
      case 107: {
        if (choice - 1 <= menuOptions.size()) {
          choice -= 1;
        }

        break;
      }
    }
  }

  clear();

  menuOptions[choice].callback();

  getch();
}
