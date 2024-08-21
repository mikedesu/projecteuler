#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int get_max_total(vector<vector<int>> &triangle, int i, int level, int n) {
  int r = 0;
  if (i >= 0 && i < n) {
    r = triangle[level][i] +
        (level < n - 1 ? max(get_max_total(triangle, i, level + 1, n),
                             get_max_total(triangle, i + 1, level + 1, n))
                       : 0);
  }
  return r;
}

int main() {
  const char *filename = "large.txt";
  FILE *fp = fopen(filename, "r");
  char buffer[1024] = {0};
  vector<vector<int>> mytriangle;
  fgets(buffer, 1024, fp);
  while (!feof(fp)) {
    vector<int> myrow;
    char *p = strtok(buffer, " ");
    while (p) {
      int d = strtol(p, NULL, 10);
      myrow.push_back(d);
      p = strtok(NULL, " ");
    }
    mytriangle.push_back(myrow);
    fgets(buffer, 1024, fp);
  }
  fclose(fp);
  cout << get_max_total(mytriangle, 0, 0, 15);
  return 0;
}
