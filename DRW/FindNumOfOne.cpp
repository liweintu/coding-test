// Question:
// Give an integer N find how many digits of 11^N are '1'
// (O(n) space and time required)

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;

#define BITWIDTH 64

int FindNumOfOne(unsigned long long In) {
  unsigned NumOfOne = 0;

  stringstream SS;
  SS << dec << In;
  string DecStr(SS.str());
  cout << "DecStr: " << DecStr << '\n';

  for (char Digit : DecStr) {
    if (Digit == '1')
      NumOfOne++;
  }

  return NumOfOne;
}

int main() {
  unsigned In;
  unsigned long long Pow;
  cout << "Enter an integer: ";
  cin >> In;
  Pow = pow(11, In);
  cout << "11 to the power of " << In << " is: " << Pow << "\n";

  cout << "Num of ones: " << FindNumOfOne(Pow) << "\n";

  return 0;
}


// end of file

