#include "ui.h"
#include <iostream>
#include <string>
#include <vector>

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

  cout << "Select option:" << endl << endl;

  for (int i = 0; i < menuOptions.size(); i++) {
    cout << " " << i + 1 << " - " << menuOptions[i].name << endl;
  }

  int choice;

  while (true) {
    cout << endl << " > ";

    cin >> choice;

    if (choice - 1 < menuOptions.size() && choice >= 1) {
      break;
    }
  }

  clearConsole();
  menuOptions[choice - 1].callback();

  further();
}

void UI::clearConsole() {
  cout << "\x1B[2J\x1B[H";
}

int UI::further() {
  string input;
  cout << "\nPress enter to continue ";
  getline(cin, input);
  cin.ignore();

  return 0;
}
