#include <cmath>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
// #include <chrono>
#include <sys/time.h>

using std::cout;
using std::endl;
using std::sqrt;
using std::string;
using std::to_string;
using std::vector;

// using namespace std::chrono;

#define ROWS 21
#define COLS 21

// bool lattice[ROWS][COLS];

// vector<vector<unsigned long int>> path_counts;

unsigned long int path_counts[ROWS][COLS];

unsigned long int traverse_lattice(int i, int j) {
  // usleep(500000);
  if (i == ROWS - 1 && j == COLS - 1) {
    // cout << "traverse_lattice(" << i << ", " << j << "): " << 1 << endl;
    path_counts[i][j] = 1;
    return 1;
  } else if (j == COLS - 1) {
    unsigned long int v = path_counts[i][j];
    if (v == 0) {
      v = traverse_lattice(i + 1, j);
      path_counts[i][j] = v;
    }
    return v;
  } else if (i == ROWS - 1) {
    unsigned long int v = path_counts[i][j];
    if (v == 0) {
      v = traverse_lattice(i, j + 1);
      path_counts[i][j] = v;
    }
    return v;
  }
  unsigned long int v = path_counts[i][j];
  if (v == 0) {
    v = traverse_lattice(i, j + 1) + traverse_lattice(i + 1, j);
    path_counts[i][j] = v;
  }
  // cout << "traverse_lattice(" << i << ", " << j << "): " << v << endl;
  return v;
}

bool is_prime(unsigned long int n);

int main() {
  cout << "evildojo " << endl;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      path_counts[i][j] = 0;
    }
  }

  struct timeval tp;
  gettimeofday(&tp, NULL);
  long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

  // path_counts[0][0] = 0;
  // cout << path_counts[0][0] << endl;

  unsigned long int paths = traverse_lattice(0, 0);

  gettimeofday(&tp, NULL);
  long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

  long int diff = ms2 - ms;

  cout << paths << endl;
  cout << "Program took " << diff << "ms to run" << endl;

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
