#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, k;
ll gr, gs, gp;
string t;

int r = 0, s = 1, p = 2;

ll dp[MAX_N][3];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  scanf("%d %d %d", &gr, &gs, &gp);

  cin >> t;

  for (int i = 0; i < n; ++i) {
    if (i < k) {
      if (t[i] == 'r') {
        dp[i][r] = 0LL;
        dp[i][s] = 0LL;
        dp[i][p] = gp;
      } else if (t[i] == 's') {
        dp[i][r] = gr;
        dp[i][s] = 0LL;
        dp[i][p] = 0LL;
      } else if (t[i] == 'p') {
        dp[i][r] = 0LL;
        dp[i][s] = gs;
        dp[i][p] = 0LL;
      }
    } else {
      if (t[i] == 'r') {
        dp[i][r] = max(dp[i - k][s], dp[i - k][p]) + 0LL;
        dp[i][s] = max(dp[i - k][r], dp[i - k][p]) + 0LL;
        dp[i][p] = max(dp[i - k][r], dp[i - k][s]) + gp;
      } else if (t[i] == 's') {
        dp[i][r] = max(dp[i - k][s], dp[i - k][p]) + gr;
        dp[i][s] = max(dp[i - k][r], dp[i - k][p]) + 0LL;
        dp[i][p] = max(dp[i - k][r], dp[i - k][s]) + 0LL;
      } else if (t[i] == 'p') {
        dp[i][r] = max(dp[i - k][s], dp[i - k][p]) + 0LL;
        dp[i][s] = max(dp[i - k][r], dp[i - k][p]) + gs;
        dp[i][p] = max(dp[i - k][r], dp[i - k][s]) + 0LL;
      }
    }
  }

  ll ans = 0;

  for (int i = 0; i < k; ++i) {
    ans += max(dp[n - 1 - i][r], max(dp[n - 1 - i][s], dp[n - 1 - i][p]));
  }

  printf("%lld\n", ans);

  return 0;
}
