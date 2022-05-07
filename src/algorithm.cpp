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

      cout << "Enter count of elements: ";
      cin >> n;

      vector<vector<float>> data (n + 1);
      vector<float> solutions (n);

      for (int i = 0; i < n; i++) {
        data[i].push_back(0);
      }

      cout << "Enter the elements:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << " data[" << i << "][" << j << "]: ";
          cin>>data[i][j];
        }
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

      for (i = n - 1; i >= 0; i--) {
        solutions[i]=data[i][n];

        for (j = i + 1; j < n; j++) {
          if (j != i) {
            solutions[i] = solutions[i] - data[i][j] * solutions[j];
          }
        }

        solutions[i] = solutions[i] / data[i][i];
      }

      cout << endl << "Solutions:" << endl;
      for (i = 0; i < n; i++) {
        cout << solutions[i] << endl;
      }

      makeDump(data, solutions);
    }

    /**
     * Make calculations dump
     *
     * @param date date
     * @param solutions solutions
     */
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

    /**
     * Make calculations dump
     *
     * @param dump CalculationDump
     */
    void makeDump(CalculationDump dump) {
      storyDump.push(dump);
    }
};
