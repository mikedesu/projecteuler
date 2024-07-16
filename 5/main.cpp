#include <iostream>
// #include <vector>

using std::cout;
using std::endl;
// using std::vector;

int main() {

  // vector<bool> conditions;

  const int max = 20;

  for (int n = 1;; n++) {
    bool satisfies = true;
    for (int i = 1; i <= max; i++) {
      if (n % i != 0) {
        satisfies = false;
        break;
      }
    }
    // we've found our number
    if (satisfies) {
      cout << n << endl;
      break;
    }
  }

  return 0;
}
