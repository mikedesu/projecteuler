#include <iostream>

using std::cout;
using std::endl;

int main() {

  const int n = 100;

  int sum = 0;
  int sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
    sum2 += i * i;
  }

  sum *= sum;
  int diff = sum - sum2;
  cout << sum << endl;
  cout << sum2 << endl;
  cout << diff << endl;

  return 0;
}
