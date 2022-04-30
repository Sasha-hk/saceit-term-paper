#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Menu option
 *
 * @param name option name
 * @param callback function to call when select the options
 */
struct Options {
  string name;
  void* callback;
};

/**
 * Universal command line interface
 */
class CLI {
  private:
  protected:
    Options *menuOptions;
    int menuOptionsCount;

  public:
    /**
     * Default constructor
     */
    CLI() {}

    /**
     * Add menu options
     * @param options Pointer to array of Options
     */
    void setMenuOptions(string *options) {}

    /**
     * Select menu options
     */
    void selectFunctino() {}
};

#endif;
