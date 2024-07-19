#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

bool is_prime(unsigned long int n);

int main() {
  cout << "evildojo " << endl;
  return 0;
}

bool is_prime(unsigned long int n) {
  if (n < 2) {
    return false;
  }
  // for (int i = 2; i < n; i++) {
  // cout << "sqrt(" << n << "): " << sqrt(n) << endl;
  for (unsigned long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
