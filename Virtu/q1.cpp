// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>
#include <vector>

using namespace std;

int solution(int X) {
  cout << "X: " << X << "\n";
  vector<int> F;
  F.push_back(0);
  F.push_back(1);
  F.push_back(1);

  if (X < 0)
    cout << "Invalid negativ number!\n";

  if (X == 0 || X == 1) {
    cout << "Needed #Steps: " << 0 << "\n";
    return 0;
  }

  unsigned i = 2;
  while (F[i++] <= X) {
    F.push_back(F[i - 2] + F[i - 1]);
  }

  cout << "Found Range: [" << F[i - 2] << ", " << F[i - 1] << "]\n";

  int NumSteps = (X - F[i-2] <= F[i-1] - X)? X - F[i-2] : F[i-1] - X;
  cout << "NumSteps: " << NumSteps << "\n";

  return NumSteps;
}

int main() {
  solution(17);

  return 0;
}

// end of file

