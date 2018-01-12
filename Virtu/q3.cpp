// Question:
// 2. Given a non-negative integer, return all possible unique combinations by moving the digits around. Note that the most significant digit cannot be zero. For example, if input is 112, output is: 112, 121, 211.

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string &S) {
  int Dec = stoi(S);
  cout << "Dec: " << Dec << endl;

  // decimal to hex string
  stringstream SS;
  SS << hex << Dec;
  string HexStr(SS.str());
  cout << "HexStr: " << HexStr << '\n';

  for (char &Digit : HexStr) {
    if (Digit != 'A' &&
        Digit != 'B' &&
        Digit != 'C' &&
        Digit != 'D' &&
        Digit != 'E' &&
        Digit != 'F' &&
        Digit != '1' &&
        Digit != '0') {
      cout << "ERROR\n";
      return "ERROR";
    } else if (Digit == '1') {
      Digit = 'I';
    } else if (Digit == '0') {
      Digit = 'O';
    }
  }

  cout << "Hexspeak: " << HexStr << '\n';
  return HexStr;
}

int main() {
  string A("257");
  solution(A);

  return 0;
}

// end of file

