#include "cli.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CLI::CLI() {}

CLI::CLI(vector<MenuOption> options) {
  this->menuOptions = options;
}

void CLI::appendMenu(vector<MenuOption> options) {
  this->menuOptions.assign(options.end(), options.begin());
}

void CLI::resetMenu(vector<MenuOption> options) {
  this->menuOptions = options;
}

void CLI::selectOptions() {
  clearConsole();

  cout << "Select option:" << endl << endl;

  // for (int i = 0; i < menuOptions.size(); i++) {
  //   cout << " > " << menuOptions[i].name << endl;
  // }

  for (MenuOption option : menuOptions) {
    cout << " > " << option.name << endl;
  }
}

void CLI::clearConsole() {
  cout << "\x1B[2J\x1B[H";
}
