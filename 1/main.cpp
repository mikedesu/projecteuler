#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {

  cout << "hello world" << endl;

  vector<int> nums;

  const int top = 1000;

  for (int i = 1; i < top; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      nums.push_back(i);
    }
  }

  int sum = 0;

  for_each(nums.begin(), nums.end(), [&sum](int num) { sum += num; });

  cout << "sum: " << sum << endl;

  return 0;
}
