#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

string l;
ll dp[2][MAX_N];

ll ans;

int main(void) {
  // Here your code !
  cin >> l;

  dp[0][0] = 1LL;

  for (int i = 0; i < l.size(); ++i) {
    // a + b == 0
    {
      if (l[i] == '0') {
        dp[0][i + 1] += dp[0][i];
        dp[0][i + 1] %= MOD;
        dp[1][i + 1] += dp[1][i];
        dp[1][i + 1] %= MOD;
      } else {
        dp[1][i + 1] += (dp[0][i] + dp[1][i]);
        dp[1][i + 1] %= MOD;
      }
    }

    // a + b == 1
    {
      if (l[i] == '0') {
        dp[1][i + 1] += 2 * dp[1][i];
        dp[1][i + 1] %= MOD;
      } else {
        dp[0][i + 1] += 2 * dp[0][i];
        dp[0][i + 1] %= MOD;
        dp[1][i + 1] += 2 * dp[1][i];
        dp[1][i + 1] %= MOD;
      }
    }
  }

  ans = dp[0][l.size()] + dp[1][l.size()];

  ans %= MOD;

  printf("%lld\n", ans);

  return 0;
}
