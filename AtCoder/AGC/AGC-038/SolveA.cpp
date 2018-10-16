#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(1e3 + 5);
const int MAX_W = (int)(1e3 + 5);

int h, w, a, b;
int field[MAX_H][MAX_W];

int main(void) {
  // Here your code !
  scanf("%d %d %d %d", &h, &w, &a, &b);

  for (int i = 0; i < b; ++i) {
    for (int j = 0; j < a; ++j) {
      field[i][j] = 0;
    }
  }

  for (int i = 0; i < b; ++i) {
    for (int j = a; j < w; ++j) {
      field[i][j] = 1;
    }
  }

  for (int i = b; i < h; ++i) {
    for (int j = 0; j < a; ++j) {
      field[i][j] = 1;
    }
  }

  for (int i = b; i < h; ++i) {
    for (int j = a; j < w; ++j) {
      field[i][j] = 0;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      printf("%d", field[i][j]);
    }
    printf("\n");
  }

  return 0;
}
