#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n, m;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &m);

  ans = 1LL;

  for (ll i = 1LL; i * i <= m; ++i) {
    if (m % i > 0) continue;

    ll other = m / i;

    if (i == other) {
      if (other >= n) ans = max(ans, i);
    } else {
      if (i >= n) ans = max(ans, other);
      if (other >= n) ans = max(ans, i);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
