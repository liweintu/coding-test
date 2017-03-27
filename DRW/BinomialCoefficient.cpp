// Question (Task 2):
// find the Binomial Coefficient, B(N, K).
// B(N, K) = factorial(N) / (factorial(K) * factorial(N-K))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int K) {
  if (K > N)
    return -1;

  int Min = (K < (N - K)) ? K : (N - K);
  int Max = N - Min;
  unsigned Denominator = 1;
  unsigned Numerator = 1;

  for (int i = 1, j = 1; i <= Min; i++, j++) {
    Denominator *= i;
    Numerator *= (j + Max);
  }

  cout << Numerator << " / " << Denominator << endl;
  return Numerator / Denominator;
}

int main() {
  int N, K;
  N = 5;
  K = 3;

  cout << "solution returns: " << solution(N, K) << endl;

  return 0;
}

// end of file

