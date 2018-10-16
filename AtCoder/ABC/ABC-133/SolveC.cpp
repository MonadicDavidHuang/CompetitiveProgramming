#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(2019);

ll l, r;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &l, &r);

  ans = INF;

  for (ll i = l; i <= l + MOD - 1; ++i) {
    for (ll j = i + 1LL; j <= i + MOD - 1; ++j) {
      if (i >= r || j > r) continue;
      ans = min(ans, (i * j) % MOD);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
