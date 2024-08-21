#include <stdio.h>
unsigned long int matrix[80][80], path_sums[80][80];
unsigned long int traverse_lattice(int i, int j) {
  unsigned long int v = 0, a = 0, b = 0;
  if (i == 79 && j == 79) {
    v = path_sums[i][j] = matrix[i][j];
  } else if (j == 79) {
    v = path_sums[i][j];
    v = v == 0 ? matrix[i][j] + traverse_lattice(i + 1, j) : v;
    path_sums[i][j] = v;
  } else if (i == 79) {
    v = path_sums[i][j];
    v = v == 0 ? matrix[i][j] + traverse_lattice(i, j + 1) : v;
    path_sums[i][j] = v;
  } else {
    v = path_sums[i][j];
    if (v == 0) {
      a = traverse_lattice(i, j + 1);
      b = traverse_lattice(i + 1, j);
      v = a < b ? matrix[i][j] + a : matrix[i][j] + b;
      path_sums[i][j] = v;
    }
  }
  return v;
}
void main() {
  FILE *file = fopen("matrix.txt", "r");
  for (int i = 0; i < 80; i++)
    for (int j = 0; j < 80; j++)
      fscanf(file, "%lu", &matrix[i][j]);
  printf("Minimum sum: %lu\n", traverse_lattice(0, 0));
}
