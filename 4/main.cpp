#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

bool is_palindrome(unsigned int n) {
  if (n == 0 || n < 10) {
    return true;
  }

  int test = 10;
  for (test = 10;; test *= 10) {
    int result = n / test;
    if (result == 0) {
      test /= 10;
      break;
    }
  }
  // get the number at the current power position
  int test_copy = test;
  vector<int> digits;
  for (; test > 0; test /= 10) {
    int num = n / test;
    digits.push_back(num);
    n = n - (num * test);
  }
  if (digits.size() % 2 == 0) {
    bool flag = true;
    for (int i = 0; i < digits.size() / 2; i++) {
      if (digits[i] != digits[digits.size() - i - 1]) {
        flag = false;
        break;
      }
    }
    return flag;
  }
  return false;
}

int main() {
  int largest = -1;
  for (int i = 999; i >= 100; i--) {
    for (int j = 999; j >= 100; j--) {
      if (is_palindrome(i * j)) {
        if (i * j > largest) {
          // cout << "i:" << i << endl;
          // cout << "j:" << j << endl;
          largest = i * j;
        }
      }
    }
  }
  cout << largest << endl;
  return 0;
}
