#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int sx, sy;
int tx, ty;

int main(void) {
  // Here your code !
  scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

  int x = sx;
  int y = sy;

  while (x < tx) {
    x += 1;
    printf("R");
  }

  while (y < ty) {
    y += 1;
    printf("U");
  }

  while (sx < x) {
    x -= 1;
    printf("L");
  }

  while (sy < y) {
    y -= 1;
    printf("D");
  }

  y -= 1;
  printf("D");

  while (x < tx + 1) {
    x += 1;
    printf("R");
  }

  while (y < ty) {
    y += 1;
    printf("U");
  }

  x -= 1;
  printf("L");

  y += 1;
  printf("U");

  while (sx - 1 < x) {
    x -= 1;
    printf("L");
  }

  while (sy < y) {
    y -= 1;
    printf("D");
  }

  x += 1;
  printf("R");

  printf("\n");

  return 0;
}
