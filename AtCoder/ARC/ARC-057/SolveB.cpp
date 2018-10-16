#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);

int n;
ll k;
ll a[MAX_N];

ll dp[MAX_N][MAX_N];  // min-win-times of satisfied j times at day i

int ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  ll whole = 0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
    whole += a[i];
  }

  if (whole == k) {
    ans = 1;
    printf("%d\n", ans);
    return 0;
  }

  if (k == 0) {
    ans = 0;
    printf("%d\n", ans);
    return 0;
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = INF;
    }
  }

  ll sum_a = a[1];

  dp[0][0] = 0LL;
  dp[1][0] = 0LL;
  dp[1][1] = 1LL;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] == INF) continue;  // impossible case

      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);  // no win at day (i + 1)

      ll min_win = (dp[i][j] * a[i + 1]) / sum_a +
                   1;  // min-win-times to get satisfied at day (i + 1)

      if (min_win <= a[i + 1]) {  // cannot win more than times of games
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + min_win);
      }
    }

    sum_a += a[i + 1];
  }

  for (int j = 0; j <= n; ++j) {
    if (dp[n][j] <= k) ans = max(ans, j);
  }

  printf("%d\n", ans);
  return 0;

  return 0;
}
