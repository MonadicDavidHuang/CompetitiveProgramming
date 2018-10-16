#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll r, g, b, n;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld %lld", &r, &g, &b, &n);

  ans = 0;

  for (ll i = 0; i <= n; ++i) {
    for (ll j = 0; j <= n; ++j) {
      ll cur = r * i + g * j;
      if (cur > n) continue;
      if ((n - cur) % b == 0) {
        ans += 1;
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
