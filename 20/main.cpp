#include <cmath>
#include <gmp.h>
#include <iostream>

using namespace std;

int main() {
  unsigned long int n = 100;
  unsigned long int sum = 0;
  char buffer[1024] = {0};
  char *p;
  mpz_t big_n;
  FILE *infile;
  FILE *outfile;
  mpz_init_set_ui(big_n, 1);
  while (n > 1) {
    mpz_mul_ui(big_n, big_n, n);
    n--;
  }
  outfile = fopen("100factorial.txt", "w");
  mpz_out_str(outfile, 10, big_n);
  fclose(outfile);
  mpz_clear(big_n);

  infile = fopen("100factorial.txt", "r");
  fread(buffer, 1, 1024, infile);
  fclose(infile);
  p = buffer;
  while (*p != 0) {
    unsigned int v = *p - 48;
    sum += v;
    p++;
  }
  cout << sum << endl;

  return 0;
}
