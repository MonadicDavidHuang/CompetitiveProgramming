#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);
const int MAX_H = (int)(1e4 + 5);

int h, n;

int a[MAX_N], b[MAX_N];

ll dp[MAX_N][MAX_H];

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(a[i]), &(b[i]));
  }

  for (int j = 0; j <= h; ++j) {
    for (int i = 0; i <= n; ++i) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0LL;

  for (int j = 0; j <= h; ++j) {
    for (int i = 0; i < n; ++i) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

      int target_index = j + a[i];
      target_index = target_index >= h ? h : target_index;

      dp[i + 1][target_index] =
          min(dp[i + 1][target_index], dp[i + 1][j] + b[i]);
    }
  }

  ll ans = dp[n][h];

  printf("%lld\n", ans);

  return 0;
}
