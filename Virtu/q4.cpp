// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A) {
  vector<int> Old_A(A);
  bool Changed = false;

  do {
    Changed = false;

    for (unsigned i = 1; i < A.size() - 1; ++i) {
      if (Old_A[i-1] > Old_A[i] && Old_A[i+1] > Old_A[i]) {
        A[i]++;
        Changed = true;
      } else if (Old_A[i-1] < Old_A[i] && Old_A[i+1] < Old_A[i]) {
        A[i]--;
        Changed = true;
      }
    }
    
    Old_A = A;
  } while (Changed);

  for (int I : A)
    cout << I << ", ";

  cout << endl;

  return A;
}

int main() {
  vector<int> A;
  A.push_back(1);
  A.push_back(6);
  A.push_back(3);
  A.push_back(4);
  A.push_back(3);
  A.push_back(5);
  
  // A.push_back(100);
  // A.push_back(50);
  // A.push_back(40);
  // A.push_back(30);

  solution(A);

  return 0;
}

// end of file

