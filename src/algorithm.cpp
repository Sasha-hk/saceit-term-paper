#include "../include/stack.h"
#include "../include/date.h"
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
  int n;
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

    /**
     * Make new calculation with user input
     */
    void calculate() {
      int n, i, j, k;
      float tmp;

      cout.precision(4);
      cout.setf(ios::fixed);

      cout << "Enter count of elements: ";
      cin >> n;

      vector<vector<float>> data (n + 1);
      vector<float> solutions (n);

      // Enter data
      cout << "Enter the elements:\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
          cout << " data[" << i << "][" << j << "]: ";
          cin >> tmp;
          data[i].push_back(tmp);
        }
      }

      // Make calculations
      CalculationDump dump = solve(data, solutions, n);

      solutions = dump.solutions;

      // Show solutions
      cout << endl << "Solutions:" << endl;
      for (i = 0; i < n; i++) {
        cout << solutions[i] << endl;
      }

      saveDump(dump);
    }

    /**
     * Make calculation based on dump
     * @param dump previous caldulatoin
     */
    void seePrevious(CalculationDump dump) {
      vector<vector<float>> data = dump.data;
      vector<float> solutions = dump.solutions;
      int n = dump.n;

      cout << "Time: " << dump.datetime << endl << endl;

      cout << "Enter the elements:\n";
      for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
          cout << " data[" << i << "][" << j << "]: " << data[i][j] << endl;
        }
      }

      cout << endl << "Solutions:" << endl;
      for (int i = 0; i < n; i++) {
        cout << solutions[i] << endl;
      }
    }

    /**
     * Solve Jordan Gauss algorithm
     *
     * @param data data
     * @param solutions solutions
     * @param n n
     */
    CalculationDump solve(
      vector<vector<float>> data,
      vector<float> solutions,
      int n
    ) {
      int i, j, k;

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

      return makeDump(data, solutions, n);
    }

    /**
     * Make calculations dump
     *
     * @param date date
     * @param solutions solutions
     */
    CalculationDump makeDump(
      vector<vector<float>> data,
      vector<float> solutions,
      int n
    ) {
      Date date = Date();

      return {
        data,
        solutions,
        date.getString(),
        n,
      };
    }


    /**
     * Make calculations dump
     *
     * @param dump CalculationDump
     */
    void saveDump(CalculationDump dump) {
      storyDump.push(dump);
    }

    /**
     * Get latest dump
     */
    CalculationDump popStory() {
      return storyDump.pop();
    }

    /**
     * Get dump size
     */
    int dumpSize() {
      return storyDump.getTop();
    }
};
