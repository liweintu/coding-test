// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
  int MaxApples = 0;
  int Cap = 5000 - A[0];

  sort(A.begin() + 1, A.end());

  for (int I : A)
    cout << "I: " << I << "\n";

  int SumWeight = 0;
  for (vector<int>::iterator it = A.begin() + 1; it != A.end(); ++it) {
    SumWeight += *it;

    if (SumWeight <= Cap)
      MaxApples++;
    else
      break;
  }

  cout << "MaxApples: " << MaxApples << "\n";
  return MaxApples;
}

int main() {
  vector<int> A;
  A.push_back(4650);
  A.push_back(150);
  A.push_back(150);
  A.push_back(150);
  A.push_back(0);
  A.push_back(0);
  A.push_back(0);
  A.push_back(0);
  solution(A);

  return 0;
}

// end of file

