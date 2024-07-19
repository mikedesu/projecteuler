#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

const inline unsigned long int triangle_number(const int n) {
  unsigned long int sum = 0;
  for (unsigned long int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

const inline unsigned long int num_divisors(const int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
    return 2;
  }

  unsigned long int count = 2;
  // unsigned long int half_n = n / 2;

  for (unsigned long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      count += 2;
    }
  }

  return count;
}

int main() {

  unsigned long int start_time = time(NULL);

  cout << "evildojo " << endl;

  // cout << triangle_number(7) << endl;
  // cout << num_divisors(triangle_number(7)) << endl;

  unsigned long int i = 1;

  unsigned long int max_d = 0;
  unsigned long int max_i = 0;
  unsigned long int max_t = 0;

  vector<unsigned long int> triangle_numbers;
  vector<unsigned long int> divisor_counts;

  cout << "computing triangle numbers and divisor counts..." << endl;

  for (i = 1; i <= 20000; i++) {
    unsigned long int t = triangle_number(i);
    unsigned long int d = num_divisors(t);
    triangle_numbers.push_back(t);
    divisor_counts.push_back(d);
  }

  cout << "searching for largest divisor count..." << endl;

  for (i = 0; i < divisor_counts.size(); i++) {
    unsigned long int d = divisor_counts[i];
    if (d > 500) {
      max_t = triangle_numbers[i];
      max_d = d;
      max_i = i;
      break;
    }
  }

  cout << "i:" << i << endl;
  cout << "max_t:" << max_t << endl;
  cout << "max_d:" << max_d << endl;

  unsigned long int end_time = time(NULL);
  unsigned long int diff_time = end_time - start_time;

  cout << "Program took " << diff_time << " seconds";

  return 0;
}
