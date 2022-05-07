#include "../lib/stack.h"
#include "../lib/date.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

struct StoryDump {
  vector<vector<float>> data;
  vector<float> solutions;
  string datetime;
};

/**
 * Implementation Jordan Gauss algorithm
 */
class JordanGauss {
  protected:
    Stack<StoryDump> storyDump;

  public:
    JordanGauss() {
      storyDump = Stack<StoryDump>(10);
    }

    void calculate() {
      int n, i, j, k;

      cout.precision(4);
      cout.setf(ios::fixed);

      cout << "\nEnter the no. of equations\n";
      cin >> n;

      vector<vector<float>> a (n + 1);
      vector<float> x (n);

      for (int i = 0; i < n; i++) {
        a[i].push_back(0);
      }

      cout << "\nEnter the elements of the augmented-matrix row-wise:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cin>>a[i][j];
        }
      }

      for (i=0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
          if (abs(a[i][i]) < abs(a[k][i])) {
            for (j = 0; j <= n; j++) {
              double temp = a[i][j];
              a[i][j] = a[k][j];
              a[k][j] = temp;
            }
          }
        }
      }

      cout << "\nThe matrix after Pivotisation is:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << a[i][j] << setw(16);
        }

        cout << "\n";
      }

      for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
          double t = a[k][i] / a[i][i];
          for (j = 0; j <= n; j++) {
            a[k][j] = a[k][j] - t * a[i][j];
          }
        }
      }

      cout << "\n\nThe matrix after gauss-elimination is as follows:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << a[i][j] << setw(16);
        }

        cout << "\n";
      }

      for (i = n - 1; i >= 0; i--) {
        x[i]=a[i][n];

        for (j = i + 1; j < n; j++) {
          if (j != i) {
            x[i] = x[i] - a[i][j] * x[j];
          }
        }

        x[i] = x[i] / a[i][i];
      }

      cout<<"\nThe values of the variables are as follows:\n";
      for (i = 0; i < n; i++) {
        cout << x[i] << endl;
      }

      makeDump(a, x);
    }

    void makeDump(
      vector<vector<float>> data,
      vector<float> solutions
    ) {
      Date date = Date();

      storyDump.push({
        data,
        solutions,
        date.getString(),
      });
    }
};
