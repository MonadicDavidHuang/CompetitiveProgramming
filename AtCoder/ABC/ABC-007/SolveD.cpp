#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_LOG_N = (int)(2e1 + 5);

ll a, b;

ll ans;

ll count_invalid(ll n) {
  ll dp[2][MAX_LOG_N];  // 0: jsut, 1: under

  fill_n(dp[0], MAX_LOG_N, 0);
  fill_n(dp[1], MAX_LOG_N, 0);

  string s = to_string(n);

  dp[0][0] = 1LL;

  for (int i = 0; i < s.size(); ++i) {
    int digit_num = s[i] - '0';

    for (int j = 0; j < 10; ++j) {
      if (j == 4 || j == 9) continue;

      if (j < digit_num) {
        dp[1][i + 1] += dp[0][i] + dp[1][i];
      } else if (j == digit_num) {
        dp[0][i + 1] += dp[0][i];
        dp[1][i + 1] += dp[1][i];
      } else {
        dp[1][i + 1] += dp[1][i];
      }
    }
  }

  return n - dp[0][s.size()] - dp[1][s.size()];
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &a, &b);

  ans = count_invalid(b) - count_invalid(a - 1);

  printf("%lld\n", ans);

  return 0;
}
