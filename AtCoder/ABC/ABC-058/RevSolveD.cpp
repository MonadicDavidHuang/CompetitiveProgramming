#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n, m;
ll x[MAX_N];
ll y[MAX_M];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(x[i]));
  }

  for (int i = 1; i <= m; ++i) {
    scanf("%lld", &(y[i]));
  }

  ll sum_x = 0;
  for (int i = 1; i <= n; ++i) {
    sum_x += (i - 1) * x[i] + (n - i) * -x[i];
    sum_x = sum_x % MOD;
  }

  ll sum_y = 0;
  for (int i = 1; i <= m; ++i) {
    sum_y += (i - 1) * y[i] + (m - i) * -y[i];
    sum_y = sum_y % MOD;
  }

  ans = sum_x * sum_y;
  ans = ans % MOD;

  printf("%lld\n", ans);

  return 0;
}
