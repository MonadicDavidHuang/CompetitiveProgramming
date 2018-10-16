#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;

int a = 0, c = 1, g = 2, t = 3;
ll dp[MAX_N][4][4][4];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  dp[0][t][t][t] = 1LL;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k)
        for (int l = 0; l < 4; ++l) {
          for (int m = 0; m < 4; ++m) {
            if (j == a && k == g && l == c) continue;
            if (j == a && k == c && l == g) continue;
            if (j == g && k == a && l == c) continue;
            if (k == a && l == g && m == c) continue;
            if (k == a && l == c && m == g) continue;
            if (k == g && l == a && m == c) continue;
            if (j == a && k == g && m == c) continue;
            if (j == a && l == g && m == c) continue;

            dp[i + 1][k][l][m] += dp[i][j][k][l];
            dp[i + 1][k][l][m] %= MOD;
          }
        }
  }

  ans = 0;

  for (int k = 0; k < 4; ++k)
    for (int l = 0; l < 4; ++l)
      for (int m = 0; m < 4; ++m) {
        ans += dp[n][k][l][m];
        ans %= MOD;
      }

  printf("%lld\n", ans);

  return 0;
}
