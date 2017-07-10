// Question:
// find out how many square numbers there are in the range [A, B],
// where A<=B and are both integers. Not that both A and B might be negative.

#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>

using namespace std;

int main() {
  int A, B;
  A = 10;
  B = 100;

  cout << "A: " << A << ", B: " << B << endl;

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

