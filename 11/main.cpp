#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

unsigned long int greatest_product_in_block(int matrix[][20], int row,
                                            int col) {
  // unsigned long int greatest_product_in_block(int **matrix, int row, int col)
  // {

  unsigned long int product_0 = 1;
  product_0 *= matrix[row][col];
  product_0 *= matrix[row][col + 1];
  product_0 *= matrix[row][col + 2];
  product_0 *= matrix[row][col + 3];

  unsigned long int product_1 = 1;
  product_1 *= matrix[row + 1][col];
  product_1 *= matrix[row + 1][col + 1];
  product_1 *= matrix[row + 1][col + 2];
  product_1 *= matrix[row + 1][col + 3];

  unsigned long int product_2 = 1;
  product_2 *= matrix[row + 2][col];
  product_2 *= matrix[row + 2][col + 1];
  product_2 *= matrix[row + 2][col + 2];
  product_2 *= matrix[row + 2][col + 3];

  unsigned long int product_3 = 1;
  product_3 *= matrix[row + 3][col];
  product_3 *= matrix[row + 3][col + 1];
  product_3 *= matrix[row + 3][col + 2];
  product_3 *= matrix[row + 3][col + 3];

  unsigned long int product_4 = 1;
  product_4 *= matrix[row + 0][col + 0];
  product_4 *= matrix[row + 1][col + 0];
  product_4 *= matrix[row + 2][col + 0];
  product_4 *= matrix[row + 3][col + 0];

  unsigned long int product_5 = 1;
  product_5 *= matrix[row + 0][col + 1];
  product_5 *= matrix[row + 1][col + 1];
  product_5 *= matrix[row + 2][col + 1];
  product_5 *= matrix[row + 3][col + 1];

  unsigned long int product_6 = 1;
  product_6 *= matrix[row + 0][col + 2];
  product_6 *= matrix[row + 1][col + 2];
  product_6 *= matrix[row + 2][col + 2];
  product_6 *= matrix[row + 3][col + 2];

  unsigned long int product_7 = 1;
  product_7 *= matrix[row + 0][col + 3];
  product_7 *= matrix[row + 1][col + 3];
  product_7 *= matrix[row + 2][col + 3];
  product_7 *= matrix[row + 3][col + 3];

  unsigned long int product_8 = 1;
  product_8 *= matrix[row + 0][col + 0];
  product_8 *= matrix[row + 1][col + 1];
  product_8 *= matrix[row + 2][col + 2];
  product_8 *= matrix[row + 3][col + 3];

  unsigned long int product_9 = 1;
  product_9 *= matrix[row + 0][col + 3];
  product_9 *= matrix[row + 1][col + 2];
  product_9 *= matrix[row + 2][col + 1];
  product_9 *= matrix[row + 3][col + 0];

  vector<unsigned long int> nums;
  nums.push_back(product_0);
  nums.push_back(product_1);
  nums.push_back(product_2);
  nums.push_back(product_3);
  nums.push_back(product_4);
  nums.push_back(product_5);
  nums.push_back(product_6);
  nums.push_back(product_7);
  nums.push_back(product_8);
  nums.push_back(product_9);

  unsigned long int largest = 0;
  for (auto n : nums) {
    cout << n << endl;
    if (n > largest) {
      cout << "new largest: " << n << endl;
      largest = n;
    }
  }

  return largest;
  // return product;
}

int main() {

  cout << "evildojo " << endl;

  const char *filename = "input.txt";

  FILE *infile = fopen(filename, "r");

  char buffer[1024] = {0};
  int num = -1;
  int col = 0;
  int row = 0;

  int matrix[20][20];
  // int **matrix = new int[20][20];

  while ((fscanf(infile, "%02d", &num)) != EOF) {
    matrix[row][col] = num;
    printf("%02d ", num);
    col++;
    if (col == 20) {
      row++;
      printf("\n");
      col = 0;
    }
    if (row == 20) {
      break;
    }
  }
  fclose(infile);

  unsigned long int largest = 0;
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 17; j++) {
      unsigned long int example = greatest_product_in_block(matrix, i, j);
      if (example > largest) {
        largest = example;
      }
    }
  }

  cout << "largest: " << largest << endl;

  return 0;
}
