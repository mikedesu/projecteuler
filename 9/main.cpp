#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::pow;
using std::sqrt;
using std::to_string;

int main() {

  cout << "evildojo " << endl;

  for (int a = 1;; a++) {
    for (int b = a + 1; b < 1000; b++) {
      double a_2 = a * a;
      double b_2 = b * b;
      double c_2 = a_2 + b_2;
      double c = sqrt(c_2);
      if (a + b + c == 1000) {
        cout << "Found:" << endl;
        cout << "a: " << to_string(a) << endl;
        cout << "b: " << to_string(b) << endl;
        cout << "c: " << to_string(c) << endl;
        cout << "a_2: " << to_string(a_2) << endl;
        cout << "b_2: " << to_string(b_2) << endl;
        cout << "c_2: " << to_string(c_2) << endl;
        cout << "a + b + c = " << to_string(a + b + c) << endl;
        cout << "a * b * c = " << to_string(a * b * c) << endl;
        return 0;
      }
    }
  }

  return 0;
}
