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

int solution(string &S) {
  map<char, unsigned> Letter2Count;
  for (char Letter : S) {
    Letter2Count[Letter]++;
  }

  int NumSubStr = 0;

  // count single-letter substring
  NumSubStr += S.size();

  for (pair<char, unsigned> Pair : Letter2Count) {
    char Letter = Pair.first;
    unsigned Count = Pair.second;
    if (Count <= 1)
      continue;

    for (unsigned i = 2; i <= Count; ++i) {
      string SearchTarget(i, Letter);
      int Occur = 0;
      string::size_type Pos = 0;
      while ((Pos = S.find(SearchTarget, Pos)) != string::npos) {
        ++Occur;
        Pos++;
      }

      if (Occur == 0)
        break;

      NumSubStr += Occur;
    }
  }

  cout << "NumSubStr: " << NumSubStr << endl;
  return NumSubStr;
}

int main() {
  string A("zzzyzaa");
  solution(A);

  return 0;
}

// end of file

