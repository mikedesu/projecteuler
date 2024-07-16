#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::sqrt;

bool is_prime(int n) {
  if (n < 2) {
    return false;
  }
  // for (int i = 2; i < n; i++) {
  // cout << "sqrt(" << n << "): " << sqrt(n) << endl;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {

  int num_primes = 0;
  int n = 0;
  for (int i = 1; num_primes < 10001; i++) {
    if (is_prime(i)) {
      // cout << i << endl;
      n = i;
      num_primes++;
    }
  }
  cout << n << endl;

  return 0;
}
