#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(1e2 + 5);
const int MAX_W = (int)(1e1 + 5);
const ll MOD = (int)(1e9 + 7);

int h, w, k;

ll dp[MAX_H][MAX_W];
ll cf[MAX_H][MAX_W][3];

int main(void) {
  // Here your code !
  scanf("%d %d %d\n", &h, &w, &k);

  if (w == 1) {
    printf("%lld\n", 1);
    return 0;
  }

  for (int i = 0; i < h; ++i) {
    for (int bit = 0; bit < (1 << w - 1); ++bit) {
      if ((bit & (bit << 1)) != 0) continue;

      if (bit & (1 << 1 - 1)) {
        cf[i][1][2] += 1;
      } else
        cf[i][1][1] += 1;

      for (int j = 2; j <= w - 1; ++j) {
        if (bit & (1 << j - 1)) {
          cf[i][j][2] += 1;
        } else if (bit & (1 << j - 1 - 1)) {
          cf[i][j][0] += 1;
        } else
          cf[i][j][1] += 1;
      }

      if (bit & (1 << w - 1 - 1)) {
        cf[i][w][0] += 1;
      } else
        cf[i][w][1] += 1;
    }
  }

  dp[0][1] = 1;

  for (int i = 0; i < h; ++i) {
    dp[i + 1][1 + 1] += (cf[i][1][2] * dp[i][1]) % MOD;
    dp[i + 1][1 + 1] %= MOD;
    dp[i + 1][1 + 0] += (cf[i][1][1] * dp[i][1]) % MOD;
    dp[i + 1][1 + 0] %= MOD;

    for (int j = 2; j <= w - 1; ++j) {
      dp[i + 1][j + 1] += (cf[i][j][2] * dp[i][j]) % MOD;
      dp[i + 1][j + 0] += (cf[i][j][1] * dp[i][j]) % MOD;
      dp[i + 1][j + -1] += (cf[i][j][0] * dp[i][j]) % MOD;

      dp[i + 1][j + 1] %= MOD;
      dp[i + 1][j + 0] %= MOD;
      dp[i + 1][j + -1] %= MOD;
    }

    dp[i + 1][w + 0] += (cf[i][w][1] * dp[i][w]) % MOD;
    dp[i + 1][w + 0] %= MOD;
    dp[i + 1][w + -1] += (cf[i][w][0] * dp[i][w]) % MOD;
    dp[i + 1][w + -1] %= MOD;
  }

  printf("%lld\n", dp[h][k]);

  return 0;
}
