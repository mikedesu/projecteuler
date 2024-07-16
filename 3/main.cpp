

#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

bool is_prime(int n);

int main() {

  vector<unsigned long int> primes;

  int num_to_compute = 10000;

  for (unsigned long int i = 0; i < num_to_compute; i++) {
    if (is_prime(i)) {
      // cout << i << endl;
      primes.push_back(i);
    }
  }

  // int n = 13195;
  unsigned long int n = 600851475143;

  vector<unsigned long int> factors;

  for (unsigned long int i = 0; i < primes.size(); i++) {
    unsigned long int prime = primes[i];
    unsigned long int result = n % prime;
    if (result == 0) {
      n /= prime;
      factors.push_back(prime);
      cout << prime << endl;
    }
  }

  return 0;
}

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
