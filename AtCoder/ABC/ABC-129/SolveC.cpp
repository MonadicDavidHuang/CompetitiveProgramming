#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n, m;
bool broken[MAX_N];

ll dp[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i <= n; ++i) {
    broken[i] = false;
  }

  for (int i = 0; i < m; ++i) {
    int tmp;
    scanf("%d", &tmp);

    broken[tmp] = true;
  }

  dp[0] = 1LL;

  for (int i = 0; i < n; ++i) {
    if (broken[i]) continue;

    dp[i + 1] += dp[i];
    dp[i + 1] %= MOD;

    dp[i + 2] += dp[i];
    dp[i + 2] %= MOD;
  }

  printf("%lld\n", dp[n]);

  return 0;
}
