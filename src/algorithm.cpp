#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std;

class JordanGauss {
  public:
    JordanGauss() {}

    void calculate() {
      int n, i, j, k;
      float ratio;

      cout << "Size: ";
      cin >> n;

      // Prepare data structures
      float **matrix = new float*[n];
      float *solution = new float[n + 1];

      for (int i = 0; i <= n; i++) {
        matrix[i] = new float[n];
      }

      // Fill matrix
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
          cout << "a[" << i << "]" << j << "]= ";
          cin >> matrix[i][j];
        }
      }

      for (i = 1; i <= n; i++) {
        if (matrix[i][i] == 0.0) {
          cout << "Mathematical Error!";
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

      cout << endl << "Solution: " << endl;

      for (i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << solution[i] << endl;
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
