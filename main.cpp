#include <ncurses.h>

using namespace std;

int main() {
  int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
  printw("Type any character to see it in bold\n");

  while ((ch = getch()) != '.') {
    if(ch == KEY_F(1)){
      printw("F1 Key pressed");
    }
    else {
      printw("The pressed key is ");
      attron(A_BOLD);
      printw("%c", ch);
      attroff(A_BOLD);
    }

    refresh();
  }

  refresh();
  endwin();

  return 0;
}
