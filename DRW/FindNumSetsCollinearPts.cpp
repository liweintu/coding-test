// Question:
// calculating the number of the sets of points that are collinear

#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isCollinear(pair<int,int> P1, pair<int,int> P2, pair<int,int> P3) {
  return (P1.second - P2.second) * (P1.first - P3.first)
         == (P1.second - P3.second) * (P1.first - P2.first);
}

int solution(vector<pair<int,int>> Points) {
  int NumSets = 0;

  set<int> VerticalX;
  set<pair<float,float>> SlopeCross;

  for (int i = 0; i < Points.size(); i++) {
    for (int j = i + 1; j < Points.size(); j++) {
      for (int k = 0; k < Points.size(); k++) {
        if (k == i || k == j)
          continue;

        if (isCollinear(Points[i], Points[j], Points[k])) {
          // handle vertical lines
          if (Points[i].first == Points[j].first) {
            if (VerticalX.insert(Points[i].first).second)
              NumSets++;

            break;
          }

          float Slope = (Points[j].second - Points[i].second) /
                        (Points[j].first - Points[i].first);
          float Cross = Points[i].second - (Slope * Points[i].first);

          if (SlopeCross.insert(make_pair(Slope, Cross)).second) {
            cout << "Slope: " << Slope << endl;
            cout << "Cross: " << Cross << endl << endl;
            NumSets++;
          }

          break;
        }
      }
    }
  }

  cout << "Vertical lines: " << VerticalX.size() << endl;
  cout << "Sloping lines: " << SlopeCross.size() << endl;
  return NumSets;
}

int main() {
  vector<pair<int,int>> Points;
  Points.push_back(pair<int,int>(0, 1));
  Points.push_back(pair<int,int>(1, 1));
  Points.push_back(pair<int,int>(2, 1));
  Points.push_back(pair<int,int>(3, 1));


  Points.push_back(pair<int,int>(1, 2));
  Points.push_back(pair<int,int>(2, 2));
  Points.push_back(pair<int,int>(3, 2));

  Points.push_back(pair<int,int>(2, 3));
  Points.push_back(pair<int,int>(3, 3));

  int NumSets = solution(Points);
  cout << "# of sets of Collinear Points: " << NumSets << endl;

  return 0;
}


// end of file

