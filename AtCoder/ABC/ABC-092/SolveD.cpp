#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(1e2 + 5);
const int MAX_W = (int)(1e2 + 5);

int a, b;

int h = 100;
int w = 100;
char white = '.';
char black = '#';
char field[MAX_H][MAX_W];

void coloring(char color, int begin_h, int num) {
  if (num == 0) return;

  int cnt = 0;
  for (int i = begin_h; i < h; i += 2) {
    for (int j = 0; j < w; j += 2) {
      field[i][j] = color;
      cnt += 1;
      if (cnt >= num) return;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &b);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      field[i][j] = (i < h / 2) ? black : white;
    }
  }

  coloring(white, 0, a - 1);

  coloring(black, h / 2 + 1, b - 1);

  printf("%d %d\n", h, w);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      printf("%c", field[i][j]);
    }
    printf("\n");
  }

  return 0;
}
