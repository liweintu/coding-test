// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>

using namespace std;

bool updateDigitCount(char Pick, map<char, unsigned> &Digits) {
  if (Digits[Pick] > 0) {
    Digits[Pick]--;
    return true;
  }

  return false;
}

int main() {
  // unsigned A = 212350030;
  unsigned A = 11230;
  unsigned NumDigits = 0;

  string Num = to_string(A);
  cout << "Number String: " << Num << "\n\n";
  // const char *Digits = Num.c_str();


  map<char, unsigned> Digit2Count;
  for (char Digit : Num) {
    Digit2Count[Digit]++;
    NumDigits++;
  }

  cout << "Digit Map:\n";


  for (pair<char, unsigned> Pair : Digit2Count) {
    cout << "Digit: " << Pair.first << " => " << Pair.second << "\n";
  }

  cout << "=============\n";

  for (unsigned i = 0; i < NumDigits; ++i) {
    for (pair<char, unsigned> Pair : Digit2Count) {
      map<char, unsigned> UpdatedDigits = Digit2Count;
      char Digit = Pair.first;
      unsigned Count = Pair.second;

      if (Digit == '0')
        continue;
      
      cout << "Picked:" << Digit << "\n";

      while (updateDigitCount(Digit, UpdatedDigits)) {
        cout << Digit << "\n";

        for (pair<char, unsigned> UpdatedPair : UpdatedDigits) {
          cout << "Digit: " << UpdatedPair.first << " | " << UpdatedPair.second << "\n";
        }
      }

    }
  }

  set<string> AllCombs;

  return 0;
}



// #define BITWIDTH 32
// 
// int FindNumOfBitOne(int In) {
//   string InStr = bitset<BITWIDTH>(In).to_string();
//   cout << "Binary format: " << InStr << "\n";
//   const char *InChars = InStr.c_str();
// 
//   unsigned NumOfBitOne = 0;
// 
//   for (unsigned i = 0; i < BITWIDTH; i++) {
//     if (InChars[i] == '1') {
//       NumOfBitOne++;
//     }
//   }
// 
//   return NumOfBitOne;
// }
// 
// int main() {
//   int In;
//   cout << "Enter an integer: ";
//   cin >> In;
// 
//   cout << "Num of ones: " << FindNumOfBitOne(In) << "\n";
// 
//   return 0;
// }
// 
// 


// end of file

