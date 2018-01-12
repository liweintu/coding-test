// Question:
// find out how many square numbers there are in the range [A, B],
// where A<=B and are both integers. Not that both A and B might be negative.

#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
  int A, B;
  A = -1;
  B = 100;
  unsigned NumSqrt = 0;

  double SqrtA = sqrt(A);
  double SqrtB = sqrt(B);

  cout << "A: " << A << ", B: " << B << endl;
  cout << "sqrt of A: " << SqrtA << ", sqrt of B: " << SqrtB << endl;

  if (B < 0) {
    cout << "NumSqrt: " << 0 << endl;
    return 0;
  }

  if (B == 0) {
    cout << "NumSqrt: " << 1 << endl;
    return 0;
  }

  for (int i = A < 0 ? 0 : SqrtA; i <= SqrtB; ++i) {
    cout << "Found Sqaure Number: " << i << endl;
    NumSqrt++;
  }

  cout << "NumSqrt: " << NumSqrt << endl;

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

