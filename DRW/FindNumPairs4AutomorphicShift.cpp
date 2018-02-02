// Question:
// calculating the pairs that contribute to the automorphic cyclic shift
// given a matrix

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int solution(int **Matrix, int Rows, int Cols) {
  int OldMatrix[Rows][Cols];
  int NewMatrix[Rows][Cols];
  int NumInCol1 = 0;
  int NumInRow1 = 0;

  // initialization
  for (int j = 0; j < Rows; j++) {
    for (int k = 0; k < Cols; k++) {
      OldMatrix[j][k] = Matrix[j][k];
      NewMatrix[j][k] = Matrix[j][k];
    }
  }

  // shift right
  for (int i = 0; i < Cols - 1; i++) {
    for (int j = 0; j < Rows; j++) {
      for (int k = 0; k < Cols; k++) {
        NewMatrix[j][(k + 1) % Cols] = OldMatrix[j][k];
      }
    }

    bool IsSame = true;
    for (int j = 0; j < Rows; j++) {
      for (int k = 0; k < Cols; k++) {
        IsSame &= NewMatrix[j][k] == Matrix[j][k];
        OldMatrix[j][k] = NewMatrix[j][k];
      }
    }

    // if (memcmp(NewMatrix, Matrix, sizeof(int) * Rows * Cols) == 0)
    if (IsSame)
      NumInRow1++;
  }

  // re-initialize NewMatrix
  for (int j = 0; j < Rows; j++) {
    for (int k = 0; k < Cols; k++) {
      OldMatrix[j][k] = Matrix[j][k];
      NewMatrix[j][k] = Matrix[j][k];
    }

  }
  // shift down
  for (int i = 0; i < Rows - 1; i++) {
    for (int j = 0; j < Rows; j++) {
      for (int k = 0; k < Cols; k++) {
        NewMatrix[(j + 1) % Rows][k] = OldMatrix[j][k];
      }
    }

    bool IsSame = true;
    for (int j = 0; j < Rows; j++) {
      for (int k = 0; k < Cols; k++) {
        IsSame &= NewMatrix[j][k] == Matrix[j][k];
        OldMatrix[j][k] = NewMatrix[j][k];
      }
    }

    // if (memcmp(NewMatrix, Matrix, sizeof(int) * Rows * Cols) == 0)
    if (IsSame)
      NumInCol1++;
  }

  cout << "NumInRow1: " << NumInRow1 << endl;
  cout << "NumInCol1: " << NumInCol1 << endl;
  cout << "#pairs: " << NumInRow1 + NumInCol1 + NumInRow1 * NumInCol1 + 1 << endl;
  return 0;
}


int main() {
  int Rows = 8;
  int Cols = 8;
  int **Matrix;
  Matrix = new int *[Rows];

  for (int i = 0; i < Rows; i++) {
    Matrix[i] = new int[Cols];
  }

  // initial the matrix
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      Matrix[i][j] = (abs(i - j) % 2 == 0) ? 1 : 2;
      cout << Matrix[i][j] << " ";
    }

    cout << endl;
  }

  int NumPairs = solution(Matrix, Rows, Cols);

  return NumPairs;
}


// end of file

