#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

bool is_prime(unsigned long int n);

unsigned long int next_collatz(unsigned long int n);
unsigned long int count_collatz(unsigned long int n);

int main() {
  cout << "evildojo " << endl;

  unsigned long int largest = 0;
  unsigned long int largest_i = 0;
  for (unsigned long int i = 999999; i > 0; i--) {
    unsigned long int c = count_collatz(i);
    if (c > largest) {
      largest = c;
      largest_i = i;
    }
  }
  cout << largest_i << ": " << largest << endl;

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

unsigned long int next_collatz(unsigned long int n) {
  unsigned long int rv = 0;
  if (n % 2 == 0) {
    rv = n / 2;
  } else {
    rv = 3 * n + 1;
  }
  return rv;
}

unsigned long int count_collatz(unsigned long int n) {
  if (n == 1) {
    return 1;
  }
  unsigned long int next_n = next_collatz(n);
  return 1 + count_collatz(next_n);
}
