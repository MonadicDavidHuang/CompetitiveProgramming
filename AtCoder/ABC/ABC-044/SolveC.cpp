#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(50 + 5);
const int MAX_X = (int)(50 + 5);

int n, a;
int x[MAX_N];

ll dp[MAX_N][MAX_N][MAX_N * MAX_X];

ll ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &a);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(x[i]));
  }

  dp[0][0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k < n * MAX_X; ++k) {
        if (k - x[i] < 0) {
          dp[i][j][k] = dp[i - 1][j][k];
        } else {
          if (j > 0) dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i]];
        }
      }
    }
  }

  for (int j = 1; j <= n; ++j) {
    ans += dp[n][j][j * a];
  }

  printf("%lld\n", ans);

  return 0;
}
