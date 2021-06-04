#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);

ll n;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ll base = 1;
  for (ll i = 1; i <= n; ++i) {
    base *= i;
    base %= MOD;
  }

  ans = base;

  printf("%lld\n", ans);

  return 0;
}
