// Question:
// Give an integer N find how many digits of 11^N are '1'
// (O(n) space and time required)

#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define BITWIDTH 64

int FindNumOfOne(unsigned long long In) {
  string InStr = bitset<BITWIDTH>(In).to_string();
  cout << "Binary format: " << InStr << "\n";
  const char *InChars = InStr.c_str();

  unsigned NumOfOne = 0;

  for (unsigned i = 0; i < BITWIDTH; i++) {
    if (InChars[i] == '1') {
      NumOfOne++;
    }
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

