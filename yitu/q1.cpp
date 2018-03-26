#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n, int m) {
  vector<vector<int>> Matrix;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    Matrix.push_back(row);
  }

  int counter = 0;
  int LowerBound = 0;
  int UpperBound = 0;

  while (counter < n * m) {
    // scan increasingly
    for (int i = LowerBound; i <= UpperBound; i++) {
      if (Matrix[i].size() < m) {
        Matrix[i].push_back(counter++);
        if (counter == n * m)
          return Matrix;
      } else{
        continue;
      }
    }
    if (UpperBound < n - 1)
      UpperBound++;
    
    // scan decreasingly
    for (int i = UpperBound; i >= LowerBound; i--) {
      if (Matrix[i].size() < m) {
        Matrix[i].push_back(counter++);
        if (counter == n * m)
          return Matrix;
      } else {
        LowerBound = i + 1;
        continue;
      }
    }
    if (UpperBound < n - 1)
      UpperBound++;
  }

  return Matrix;
}

int main() {
  vector<vector<int>> M = generateMatrix(6, 6);

  for (vector<int> Row : M) {
    for (int Num : Row)
      cout << Num << "\t";

    cout << endl;
  }

  return 0;
}


// end of file

