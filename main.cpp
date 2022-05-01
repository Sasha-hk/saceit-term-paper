#include <string>
#include <iostream>

using namespace std;

class Input {
  public:
    /**
     * Default constructor
     */
    Input() {}

    /**
     * Get input
     *
     * @param message string to show before input
     * @param end get input from new line or not
     */
    template <class inputT>
    inputT input(string message) {
      bool end = false;
      inputT out;

      if (end) {
        cout << message << endl;
      } else {
        cout << message;
      }

      cin >> out;

      return out;
    }
};

int main() {
  int x;

  Input y = Input();

  x = y.input<int>(":");

  cout << x << endl;

}
