#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

string s;

int n;
int tenpow[MAX_N];
ll dp[MAX_N][13];

ll ans;

int main(void) {
  // Here your code !
  cin >> s;

  n = s.size();

  tenpow[0] = 1LL;
  for (int i = 1; i < n + 3; ++i) {
    tenpow[i] = (tenpow[i - 1] * 10 % 13) % 13;
  }

  reverse(s.begin(), s.end());

  if (s[0] == '?') {
    for (int i = 0; i <= 12; ++i) {
      dp[0][i] = (i < 10) ? 1LL : 0LL;
    }
  } else {
    for (int i = 0; i <= 12; ++i) {
      int tmp = (int)(s[0] - '0');
      dp[0][i] = (tmp == i) ? 1LL : 0LL;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int base = tenpow[i + 1];

    if (s[i + 1] != '?') {
      int tmp = (int)(s[i + 1] - '0');
      for (int d1 = 0; d1 <= 12; ++d1) {
        int key = (tmp * base + d1) % 13;
        dp[i + 1][key] += dp[i][d1];
        dp[i + 1][key] %= MOD;
      }
    } else {
      for (int d1 = 0; d1 <= 12; ++d1) {
        for (int d2 = 0; d2 <= 9; ++d2) {
          int key = (d2 * base + d1) % 13;
          dp[i + 1][key] += dp[i][d1];
          dp[i + 1][key] %= MOD;
        }
      }
    }
  }

  ans = dp[n - 1][5];

  printf("%lld\n", ans);

  return 0;
}
