// Question:
// Write a function that gets the number of squares between two numbers

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  unsigned A, B;
  unsigned NumSq = 0;

  cout << "A: ";
  cin >> A;
  cout << "B: ";
  cin >> B;

  double SqrtA = sqrt(A);
  double SqrtB = sqrt(B);

  for (unsigned i = A; i <= B; i++) {
    for (unsigned j = SqrtA; j <= SqrtB + 1; j++) {
      if ((j^2) == i) {
        cout << "found square: " << i << "\n";
        NumSq++;
        break;
      }
    }
  }

  cout << "total num of squares: " << NumSq << "\n";

  return 0;
}


// end of file

