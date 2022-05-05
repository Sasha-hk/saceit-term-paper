#include "stack.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

/**
 * Structure to store matrix data
 *
 * @param dataLength data length
 * @param data to calculate
 * @param solutionsLength solutions length
 * @param solutions solutions
 */
struct SaveResult {
  int dataLength;
  int** data;
  int solutionsLength;
  int* solutions;
  string date;
};

/**
 * Implementation Jordan Gauss algorithm
 */
class JordanGauss {
  protected:
    Stack<SaveResult> history;

  public:
    JordanGauss() {
    //  this->history = Stack<SaveResult>(10);
    }

    void calculate() {
      int ratio;
      int i, j, k, length;

      float data[10][10];
      int solutions[10 + 1];

      cout << setprecision(3) << fixed;

      cout << "Enter number of unknowns: ";
      cin >> length;

      cout << "Enter Coefficients of Augmented Matrix: " << endl;
      for (i = 1; i <= length; i++) {
        for (j = 1; j <= length + 1; j++) {
          cout << "a[" << i << "]" << j << "]= ";
          cin >> data[i][j];
        }
      }

      for (i = 1; i <= length; i++) {
        if (data[i][i] == 0.0) {
          cout << "Mathematical Error!";
          exit(0);
        }

        for (j = 1; j <= length; j++) {
          if (i != j) {
            ratio = data[j][i] / data[i][i];

            for (k = 1; k <= length + 1; k++) {
              data[j][k] = data[j][k] - ratio * data[i][k];
            }
          }
        }
      }

      for (i = 1; i <= length; i++) {
        solutions[i] = data[i][length + 1] / data[i][i];
      }

      cout << endl << "Solution: " << endl;

      for (i = 1; i <= length; i++) {
        cout << "x[" << i << "] = " << solutions[i] << endl;
      }
    }
};

      // SaveResult save;
      // save.dataLength = n;
      // // save.data;
      // save.solutionsLength = n + 1;

      // unixTime = time(NULL);
      // TIME = *localtime(&unixTime);

// int main() {
//   float a[SIZE][SIZE];
//   int x[SIZE];
//   int ratio;
//   int i, j, k, n;

//   /* Setting precision and writing floating point values in fixed-point notation. */
//   cout << setprecision(3) << fixed;

//   /* Inputs */
//   /* 1. Reading number of unknowns */
//   cout << "Enter number of unknowns: ";
//   cin >> n;

//   /* 2. Reading Augmented Matrix */
//   cout << "Enter Coefficients of Augmented Matrix: " << endl;
//   for (i = 1; i <= n; i++) {
//     for (j = 1; j <= n + 1; j++) {
//       cout << "a[" << i << "]" << j << "]= ";
//       cin >> a[i][j];
//     }
//   }

//   /* Applying Gauss Jordan Elimination */
//   for (i = 1; i <= n; i++) {
//     if (a[i][i] == 0.0) {
//       cout << "Mathematical Error!";
//       exit(0);
//     }

//     for (j = 1; j <= n; j++) {
//       if (i != j) {
//         ratio = a[j][i] / a[i][i];

//         for (k = 1; k <= n + 1; k++) {
//           a[j][k] = a[j][k] - ratio * a[i][k];
//         }
//       }
//     }
//   }

//   /* Obtaining Solution */
//   for (i = 1; i <= n; i++) {
//     x[i] = a[i][n + 1] / a[i][i];
//   }

//   /* Displaying Solution */
//   cout << endl << "Solution: " << endl;

//   for (i = 1; i <= n; i++) {
//     cout << "x[" << i << "] = " << x[i] << endl;
//   }

//   return 0;
// }
