#pragma cli
#ifndef CLI_H
#define CLI_H

#include <string>
#include <iostream>
#include <vector>

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
class CLI {
  private:
  protected:
    vector<MenuOption> menuOptions;

  public:
    /**
     * Default constructor
     */
    CLI();

    /**
     * Constructure with menu options definitions
     *
     * @param options Menu options
     */
    CLI(vector<MenuOption> options);

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

    /**
     * Clear console
     */
    void clearConsole();

    /**
     * Further after execution menu option callback
     */
    int further();
};

#endif
