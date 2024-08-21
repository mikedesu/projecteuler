#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <strings.h>
#include <vector>

using std::cerr;
// using std::bzero;
using std::cout;
using std::endl;
using std::sqrt;
using std::string;
using std::vector;

bool is_prime(unsigned long int n);

int main() {
  cout << "evildojo " << endl;

  const char *filepath = "input.txt";

  vector<string> num_strs;

  FILE *file = fopen(filepath, "r");
  if (!file) {
    cerr << "Couldn't open " << filepath << endl;
    return -1;
  }

  char buffer[1024];

  while ((fgets(buffer, 1024, file)) != NULL) {

    buffer[strlen(buffer) - 1] = 0;

    string s = buffer;
    num_strs.push_back(s);

    // cout << buffer << endl;
    bzero(buffer, 1024);
  }
  fclose(file);

  unsigned long int carry = 0;

  vector<char> digits;

  for (int i = 49; i >= 0; i--) {
    for (auto n : num_strs) {
      char c = n[i];
      // char c = n[n.length() - 1];
      int cn = c - 48;
      // cout << cn << endl;
      carry += cn;
    }
    int digit = carry % 10;
    char digit_char = digit + 48;
    digits.push_back(digit_char);

    carry /= 10;
  }

  // for (auto c : digits) {
  //   cout << c;
  // }

  for (int i = digits.size() - 1; i >= 0; i--) {
    cout << digits[i];
  }

  cout << endl;

  cout << carry << endl;
  //  int digit = carry % 10;

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
