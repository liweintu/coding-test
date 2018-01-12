// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>

using namespace std;

// global container that stores all the combinations
set<string> AllStrings;
set<string> AllCombs;
unsigned NumDigits = 0;

void updateDigitCount(char Pick, map<char, unsigned> &Digits, string Comb) {
  if (Digits[Pick] > 0) {
    Digits[Pick]--;
    Comb.append(&Pick);

    for (pair<char, unsigned> UpdatedPair : Digits) {
      if (UpdatedPair.second == 0)
        continue;

      updateDigitCount(UpdatedPair.first, Digits, Comb);
    }
  }

  if (AllStrings.insert(Comb).second) {
    cout << "Got String: " << Comb << "\n";

    if (Comb.size() == NumDigits) {
      // cout << "Found Comb: " << Comb << "\n";
      AllCombs.insert(Comb);
    }
  }

  // re-store the used Digit back to map so that the following searching for
  // combinations can continue
  Digits[Pick]++;

  return;
}


int main() {
  unsigned A = 1220;

  string Num = to_string(A);
  cout << "Number String: " << Num << "\n\n";

  map<char, unsigned> Digit2Count;
  for (char Digit : Num) {
    Digit2Count[Digit]++;
    NumDigits++;
  }

  cout << "Digit Map:\n";

  for (pair<char, unsigned> Pair : Digit2Count)
    cout << "Digit: " << Pair.first << " => " << Pair.second << "\n";

  cout << "=============\n\n";

  map<char, unsigned> UpdatedMap = Digit2Count;
  string Comb;
  for (pair<char, unsigned> Pair : Digit2Count) {
    if (Pair.first == '0')
      continue;

    if (Pair.second > 0)
      updateDigitCount(Pair.first, UpdatedMap, Comb);
  }

  for (string Comb : AllCombs)
    cout << "dump Comb:" << Comb << "\n";

  return 0;
}


// end of file

