#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
int c[MAX_N];

map<int, ll> cnt;
ll dp[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(c[i]));
  }

  c[0] = 0;

  dp[0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    if (c[i - 1] != c[i]) {
      cnt[c[i]] += dp[i - 1];
      cnt[c[i]] %= MOD;
    }

    dp[i] = cnt[c[i]];
    dp[i] %= MOD;
  }

  ans = dp[n];

  printf("%lld\n", ans);

  return 0;
}
