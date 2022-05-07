#include "../lib/stack.h"
#include "../lib/date.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

struct CalculationDump {
  vector<vector<float>> data;
  vector<float> solutions;
  string datetime;
};

/**
 * Implementation Jordan Gauss algorithm
 */
class JordanGauss {
  protected:
    Stack<CalculationDump> storyDump;

  public:
    JordanGauss() {
      storyDump = Stack<CalculationDump>(10);
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

      cout << "\nThe matrix after Pivotisation is:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << a[i][j] << setw(16);
        }

        cout << "\n";
      }

      cout<<"\nThe values of the variables are as follows:\n";
      for (i = 0; i < n; i++) {
        cout << x[i] << endl;
      }

      makeDump(a, x);
    }

    CalculationDump solve(
      int n,
      vector<vector<float>> data,
      vector<float> solutions
    ) {
      int i, j, k;

      cout.precision(4);
      cout.setf(ios::fixed);

      for (int i = 0; i < n; i++) {
        data[i].push_back(0);
      }

      for (i=0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
          if (abs(data[i][i]) < abs(data[k][i])) {
            for (j = 0; j <= n; j++) {
              double temp = data[i][j];
              data[i][j] = data[k][j];
              data[k][j] = temp;
            }
          }
        }
      }

      for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
          double t = data[k][i] / data[i][i];
          for (j = 0; j <= n; j++) {
            data[k][j] = data[k][j] - t * data[i][j];
          }
        }
      }

      cout << "\n\nThe matrix after gauss-elimination is as follows:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << data[i][j] << setw(16);
        }

        cout << "\n";
      }

      for (i = n - 1; i >= 0; i--) {
        solutions[i]=data[i][n];

        for (j = i + 1; j < n; j++) {
          if (j != i) {
            solutions[i] = solutions[i] - data[i][j] * solutions[j];
          }
        }

        solutions[i] = solutions[i] / data[i][i];
      }

      Date date = Date();

      return {
        data,
        solutions,
        date.getString(),
      };
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
