#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::sqrt;
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

int get_num_words(unordered_map<int, int> &a, int num) {

  if (num >= 1 && num <= 20) {
    return a[num];
  } else if (num >= 21 && num <= 99) {
    int r = num % 10;
    int v = num - r;
    return a[r] + a[v];
  } else if (num == 100) {
    return a[num];
  } else if (num > 100 && num < 1000) {
    int r = num % 100; // 2-digit tens and ones
    int v = num - r;   // the hundreds
    int r2 = r % 10;   // ones
    int v2 = r - r2;   // tens
    return a[v] + 3 + a[r2] + a[v2];
  }
  // num is 1000
  return 11; // onethousand
}

int main() {

  unordered_map<int, int> a;
  a[1] = 3; // one is 3 letters long
  a[2] = 3;
  a[3] = 5;
  a[4] = 4;
  a[5] = 4;
  a[6] = 3;
  a[7] = 5;
  a[8] = 5;
  a[9] = 4;
  a[10] = 3;
  a[11] = 6;
  a[12] = 6;
  a[13] = 8;    // thirteen
  a[14] = 8;    // fourteen
  a[15] = 7;    // fifteen
  a[16] = 7;    // sixteen
  a[17] = 9;    // seventeen
  a[18] = 8;    // eighteen
  a[19] = 8;    // nineteen
  a[20] = 6;    // twenty
  a[30] = 6;    // thirty
  a[40] = 5;    // forty
  a[50] = 5;    // fifty
  a[60] = 5;    // sixty
  a[70] = 7;    // seventy
  a[80] = 6;    // eighty
  a[90] = 6;    // ninety
  a[100] = 10;  // onehundred
  a[200] = 10;  // twohundred
  a[300] = 12;  // threehundred
  a[400] = 11;  // fourhundred
  a[500] = 11;  // fivehundred
  a[600] = 10;  // sixhundred
  a[700] = 12;  // sevenhundred
  a[800] = 12;  // eighthundred
  a[900] = 11;  // ninehundred
  a[1000] = 11; // onethousand

  cout << "evildojo " << endl;

  int mysum = 0;
  for (int mynum = 1; mynum < 1001; mynum++) {
    mysum += get_num_words(a, mynum);
  }
  cout << mysum << endl;

  return 0;
}
