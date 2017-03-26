// Question:
// Given an integer if that int was represented in binary how many bits
// would be set to '1'? (no time or space complexity requirements only accuracy) 

#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>

using namespace std;

#define BITWIDTH 32

int FindNumOfBitOne(int In) {
  string InStr = bitset<BITWIDTH>(In).to_string();
  cout << "Binary format: " << InStr << "\n";
  const char *InChars = InStr.c_str();

  unsigned NumOfBitOne = 0;

  for (unsigned i = 0; i < BITWIDTH; i++) {
    if (InChars[i] == '1') {
      NumOfBitOne++;
    }
  }

  return NumOfBitOne;
}

int main() {
  int In;
  cout << "Enter an integer: ";
  cin >> In;

  cout << "Num of ones: " << FindNumOfBitOne(In) << "\n";

  return 0;
}


// end of file

