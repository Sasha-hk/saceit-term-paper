// #include <stdio.h>
// #include <termios.h>
// #include <unistd.h>
// #include <fcntl.h>

// int kbhit(void)
// {
//   struct termios oldt, newt;
//   int ch;
//   int oldf;

//   tcgetattr(STDIN_FILENO, &oldt);
//   newt = oldt;
//   newt.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
//   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

//   ch = getchar();

//   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//   fcntl(STDIN_FILENO, F_SETFL, oldf);

//   if(ch != EOF)
//   {
//     ungetc(ch, stdin);
//     return 1;
//   }

//   return 0;
// }

// int main(void)
// {
//   while(!kbhit())
//     puts("Press a key!");
//   printf("You pressed '%c'!\n", getchar());
//   return 0;
// }

// ========================

#include <ncurses.h>

using namespace std;

int main() {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  while((ch = getch()) != 'E')
  {
    switch(ch) {
      case KEY_UP: {
        printw("\nUp Arrow");
        break;
      }
      case KEY_DOWN: {
        printw("\nDown Arrow");
        break;
      }
      case KEY_LEFT: {
        printw("\nLeft Arrow");
        break;
      }
      case KEY_RIGHT:
        printw("\nRight Arrow");
        break;
      default: {
        printw("\nThe pressed key is %c",ch);
      }
    }
  }

  printw("\n\Exiting Now\n");
  endwin();

  return 0;
}
