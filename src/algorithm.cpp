#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <ncurses.h>

using namespace std;

class JordanGauss {
  public:
    JordanGauss() {}

    void calculate() {
      echo();
      cbreak();
      int n, i, j, k;
      float ratio;

      char nString[10];
      printw("Size: ");
      getstr(nString);

      n = atoi(nString);

      // Prepare data structures
      float **matrix = new float*[n];
      float *solution = new float[n + 1];

      for (int i = 0; i <= n; i++) {
        matrix[i] = new float[n];
      }

      // Fill matrix
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
          cout << "\na[" << i << "]" << j << "]= ";
          printw("a[");
          printw(to_string(i).c_str());
          printw("]");
          printw(to_string(j).c_str());
          printw("]= ");
          cin >> matrix[i][j];
        }
      }

      for (i = 1; i <= n; i++) {
        if (matrix[i][i] == 0.0) {
          printw("Mathematical Error!");
          exit(0);
        }

        for (j = 1; j <= n; j++) {
          if (i != j) {
            ratio = matrix[j][i] / matrix[i][i];

            for (k = 1; k <= n + 1; k++) {
              matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
          }
        }
      }

      for (i = 1; i <= n; i++) {
        solution[i] = matrix[i][n + 1] / matrix[i][i];
      }

      printw("Solutions: ");

      for (i = 1; i <= n; i++) {
        printw("x[");
        printw(to_string(i).c_str());
        printw("] = ");
        printw(to_string(solution[i]).c_str());
        printw("\n");
      }
    }
};

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
