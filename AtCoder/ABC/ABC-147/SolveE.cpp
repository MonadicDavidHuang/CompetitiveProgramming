#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(8e1 + 5);
const int MAX_W = (int)(8e1 + 5);
const int MAX_DIFF = (int)(8e1 + 5);
const int BASE = (MAX_H + MAX_W) * MAX_DIFF;
const int SIZE = 2 * BASE;

int h, w;
int a[MAX_H][MAX_W];
int b[MAX_H][MAX_W];

bitset<SIZE> dp[MAX_H][MAX_W];

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", &(a[i][j]));
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", &(b[i][j]));
    }
  }

  int init = abs(a[0][0] - b[0][0]);

  dp[0][0].set(BASE + init);
  dp[0][0].set(BASE - init);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int diff = abs(a[i][j] - b[i][j]);

      if (i - 1 >= 0) {
        dp[i][j] |= (dp[i - 1][j] << diff);
        dp[i][j] |= (dp[i - 1][j] >> diff);
      }

      if (j - 1 >= 0) {
        dp[i][j] |= (dp[i][j - 1] << diff);
        dp[i][j] |= (dp[i][j - 1] >> diff);
      }
    }
  }

  int ans = SIZE;

  for (int i = 0; i < SIZE; ++i) {
    if (dp[h - 1][w - 1].test(i)) {
      ans = min(ans, abs(i - BASE));
    }
  }

  printf("%d\n", ans);

  return 0;
}
