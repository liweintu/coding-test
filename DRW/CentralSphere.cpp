// Question (Task 1):
// Given an array of a set of 3D points, return the minimum number of
// central spheres required to cover them

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// maximal N
#define N 100001

struct Point3D {
  int x;
  int y;
  int z;
};

int solution(vector<Point3D> &A) {
  // solution 1:
  // vector<unsigned> SquareRs;
  // for (Point3D P : A) {
  //   unsigned SquareR = 0;
  //   SquareR = (P.x * P.x) + (P.y * P.y) + (P.z * P.z);
  //   cout << "SqR: " << SquareR << "\n";
  //
  //   if (find(SquareRs.begin(), SquareRs.end(), SquareR) != SquareRs.end())
  //     continue;
  //   else {
  //     SquareRs.push_back(SquareR);
  //     cout << P.x << " " << P.y << " " << " " << P.z << endl;
  //   }
  // }
  //
  // return SquareRs.size();

  // solution 2: better solution
  set<int long> SquareRs;
  for (Point3D P : A) {
    SquareRs.insert(P.x * P.x + P.y * P.y + P.z * P.z);
  }

  return SquareRs.size();
}

int main() {
  vector<Point3D> A;
  Point3D Ps[N];

  Ps[0].x = 0; Ps[0].y = 5; Ps[0].z = 4;
  Ps[1].x = 0; Ps[1].y = 0; Ps[1].z = -3;
  Ps[2].x = -2; Ps[2].y = 1; Ps[2].z = -6;
  Ps[3].x = 1; Ps[3].y = -2; Ps[3].z = 2;
  Ps[4].x = 1; Ps[4].y = 1; Ps[4].z = 1;
  Ps[5].x = 4; Ps[5].y = -4; Ps[5].z = 3;

  for (int i = 0; i < 6; i++) {
    A.push_back(Ps[i]);
  }

  cout << "solution returns: " << solution(A) << endl;

  return 0;
}


// end of file

