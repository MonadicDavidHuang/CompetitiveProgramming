#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_K = (int)(1e3 + 5);

int n, k;

int field[2 * MAX_K][2 * MAX_K];

int get_size(int x, int y, int i, int j) {
  return field[i][j] - field[i][y] - field[x][j] + field[x][y];
}

int calc(int i, int j) {
  int black = 0;

  black += get_size(0, 0, i, j);                  // current
  black += get_size(i, j, i + k, j + k);          // top right
  black += get_size(i + k, j + k, 2 * k, 2 * k);  // top ritht top right
  black += get_size(i + k, 0, 2 * k, j);          // top
  black += get_size(0, j + k, i, 2 * k);          // right

  int white = n - black;
  int ret = max(black, white);

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    ll x, y;
    char c;

    scanf("%lld %lld %c", &x, &y, &c);

    if (c == 'W') x += (ll)(k);

    x %= (ll)(2 * k);
    y %= (ll)(2 * k);

    x += 1;
    y += 1;

    field[x][y] += 1;
  }

  for (int i = 1; i <= 2 * k; ++i) {
    for (int j = 1; j <= 2 * k; ++j) {
      field[i][j] += field[i][j - 1];
      field[i][j] += field[i - 1][j];
      field[i][j] -= field[i - 1][j - 1];
    }
  }

  int ans = -1;

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      ans = max(ans, calc(i, j));
    }
  }

  printf("%d\n", ans);
  return 0;
}
