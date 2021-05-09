#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e12 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
int r[MAX_N], c[MAX_N];

ll dp[MAX_N][MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &r[i], &c[i]);
  }

  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0LL;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      if (i == j) continue;

      dp[i][j] = INF;

      for (int k = i - 1; k >= j; --k) {
        ll split_by_k = dp[i][k + 1] + dp[k][j] + r[j] * c[i] * c[k];

        dp[i][j] = min(dp[i][j], split_by_k);
      }
    }
  }

  ll ans = dp[n - 1][0];

  printf("%lld\n", ans);

  return 0;
}
