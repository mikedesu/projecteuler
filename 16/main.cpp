#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::pow;
using std::sqrt;
using std::string;
using std::to_string;
using std::vector;

// bool is_prime(unsigned long int n);

int main() {
  cout << "evildojo " << endl;

  long double n = powl(2, 1000);
  string s = to_string(n);
  unsigned int sum = 0;
  unsigned int index = s.find('.');
  for (int i = 0; i < index; i++) {
    unsigned int v = s[i] - '0';
    sum += v;
  }
  cout.precision(100000);
  cout << n << endl;
  cout << sum << endl;

  return 0;
}

/*
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
*/
