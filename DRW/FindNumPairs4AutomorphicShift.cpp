// Question:
// calculating the number of the sets of points that are collinear

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int solution(int **Matrix, int Rows, int Cols) {


  return 0;
}


int main() {
  int Rows = 4;
  int Cols = 4;
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

