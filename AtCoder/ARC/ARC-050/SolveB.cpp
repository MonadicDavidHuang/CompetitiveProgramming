#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll r, b;
ll x, y;

bool check(ll k) {
  if (r - k < 0 || b - k < 0) return false;

  ll available = (r - k) / (x - 1) + (b - k) / (y - 1);
  return available >= k;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &r, &b);

  scanf("%lld %lld", &x, &y);

  ll ok = 0LL;
  ll ng = (ll)(1e18) + 3LL;

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2LL;
    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  ll ans = ok;

  printf("%lld\n", ans);

  return 0;
}
