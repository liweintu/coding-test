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
  int MaxSeparate = 0;
  int MaxMerge = 0;

  int LastItem = *A.begin();

  vector<int> Maxes;
  int counter = 0;
  
  for (int i : A) {
    if (i == LastItem) {
      counter++;
    } else {
      Maxes.push_back(counter);
      counter = 1
    }
    LastItem = i;
  }

  sort(Maxes.begin(), Maxes.end());
  MaxSeparate += Maxes.back();
  Maxes.pop();
  MaxSeparate += Maxes.back();

  int Inverted = 0;
  bool Exit = false
  counter = 0;

  for (int i : A) {
    if (Inverted == 3) {
      break;
    }
    if (i == LastItem) {
      counter++;
    } else {
      Inverted++;
      counter++;
    }
  }
  MaxMerge = counter;

  return max(MaxSeparate, MaxMerge);  

}

