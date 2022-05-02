#pragma ui
#ifndef UI_H
#define UI_H

#include <string>
#include <iostream>
#include <vector>
#include <ncurses.h>

using namespace std;

/**
 * Menu option
 *
 * @param name option name
 * @param callback function to call when select the options
 */
struct MenuOption {
  string name;
  void (*callback)(void);
};

/**
 * Universal command line interface
 */
class UI {
  private:
    /**
     * Show menu
     * @param active active option
     */
    void showMenu(int active);

  protected:
    vector<MenuOption> menuOptions;

  public:
    /**
     * Default constructor
     */
    UI();

    /**
     * Constructure with menu options definitions
     *
     * @param options Menu options
     */
    UI(vector<MenuOption> options);

    /**
     * Add menu options
     *
     * @param options Vector of menu Options
     */
    void appendMenu(vector<MenuOption> options);


    /**
     * Reset menu
     *
     * @param options Vector of menu Options
     */
    void resetMenu(vector<MenuOption> options);

    /**
     * Select menu option
     */
    void selectOptions();
};

#endif
