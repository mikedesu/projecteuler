#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> fibs;

int main() {
  fibs.push_back(0);
  fibs.push_back(1);

  const int max = 4000000;
  // const int n = 12;
  int sum = 0;

  // generate fibs vector
  for (int i = 2;; i++) {
    const int value = fibs[i - 1] + fibs[i - 2];

    if (value > max) {
      break;
    }

    if (value % 2 == 0) {
      sum += value;
    }

    fibs.push_back(value);
  }

  // print fibs vector
  // for (int i = 0; i < fibs.size(); i++) {
  //  cout << fibs[i] << endl;
  //}

  // cout << "length: " << fibs.size() << endl;

  cout << "sum: " << sum << endl;

  return 0;
}
