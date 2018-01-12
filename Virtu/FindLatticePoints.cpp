// Question:
// 3. lattice points that lie inside (exclusive) a circle of radius R where R is an integer.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>
#include <utility>

using namespace std;

// global container that stores lattice points
set<pair<int, int>> AllLatPts;

bool isInCircle(unsigned X, unsigned Y, unsigned R) {
  return (X*X + Y*Y < R*R) ? true : false;
}

int main() {
  unsigned R = 6;

  if (R == 0) {
    cout << "No Lattic Point!\n";
    return 0;
  }

  if (R == 1) {
    cout << "Found Lattic Point: (0, 0)\n";
    return 0;
  }

  for (unsigned i = 1; i < R ; ++i) {
    for (unsigned j = 1; isInCircle(i, j, R); ++j) {
      AllLatPts.insert(make_pair(i, j));

      // also add the symmetric lattice points in other quadrants
      int Minus_i = 0 - i;
      int Minus_j = 0 - j;
      AllLatPts.insert(make_pair(Minus_i, j));
      AllLatPts.insert(make_pair(i, Minus_j));
      AllLatPts.insert(make_pair(Minus_i, Minus_j));
    }
  }

  // add lattic points on X and Y axes
  int Minus_R = 0 - R;
  for (int k = Minus_R + 1; k < int(R); ++k) {
    AllLatPts.insert(make_pair(k, 0));
    AllLatPts.insert(make_pair(0, k));
  }

  for (pair<int, int> P : AllLatPts)
    cout << "Found Lattic Point: (" << P.first << ", " << P.second << ")\n";

  return 0;
}


// end of file

