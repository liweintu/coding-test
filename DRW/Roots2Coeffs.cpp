// Question (Task 3):
// Given an array of roots, calculate the sum of all coefficients for the
// equivalent polynomial

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

  // solution 1 (bad):
  // int Sum = 0;
  // vector<int> Coeffs;

  // // initialize the coefficients to 0s
  // for (unsigned i = 0; i <= A.size(); i++) {
  //   Coeffs.push_back(0);
  // }
  //
  // // initilize the coefficients for the first Root
  // Coeffs[0] = A[0];
  // Coeffs[1] = 1;

  // for (unsigned j = 1; j < A.size(); j++) {
  //   int Root = A[j];
  //   cout << "Root: " << Root << endl;
  //   Coeffs[j + 1] = 1;

  //   for (unsigned k = j; k > 0; k--) {
  //     Coeffs[k] = Root * Coeffs[k] + Coeffs[k - 1];
  //   }
  //   Coeffs[0] *= Root;
  // }

  // for (unsigned l = 0; l < Coeffs.size(); l++) {
  //   cout << Coeffs[l] << " x^" << l << endl;
  //   Sum += Coeffs[l];
  // }

  // solution 2 (good): the sum of coefficients is just the value of the
  // polynomial when X = 1, i.e. value = (1+Root1) * (1+Root2) * ... * (1+RootN)

  int Products = 1;
  for (int Root : A) {
    Products *= (Root + 1);
  }

  cout << "Products: " << Products << endl;
  return Products;
}

int main() {
  vector<int> A;

  A.push_back(-2);
  A.push_back(-4);
  A.push_back(4);

  int Sum = solution(A);

  cout << "solution returns: " << Sum << endl;

  return 0;
}


// end of file

