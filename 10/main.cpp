#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

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

int main() {

  cout << "evildojo " << endl;

  vector<unsigned long int> primes;

  // unsigned int max = 10;
  unsigned long int max = 2000000;

  for (unsigned long int i = 2; i < max; i++) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  unsigned long int sum = 0;
  for (int i = 0; i < primes.size(); i++) {
    sum += primes[i];
  }

  // cout << LONG_MAX << endl;
  // cout << INT_MAX << endl;
  cout << sum << endl;

  return 0;
}
