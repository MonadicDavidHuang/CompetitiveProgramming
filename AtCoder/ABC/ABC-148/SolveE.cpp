#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

ll g1(ll n, ll p) {
  if (n == 0LL) return 0LL;
  return n / p + g1(n / p, p);
}

ll g2(ll n, ll p) {
  if (n % 2LL == 0LL) {
    ll ret = g1(n / 2, p);
    if (p == 2LL) ret += n / 2LL;
    return ret;
  } else {
    return g1(n, p) - g2(n - 1LL, p);
  }
}

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ll ans = min(g2(n, 2LL), g2(n, 5LL));

  printf("%lld\n", ans);

  return 0;
}
