#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll a, b;

int n;

ll ans;

ll calc(int digit, ll t) {
  t += 1LL;
  ll window = 1LL << (digit + 1);

  ll div = t / window;
  ll mod = t % window;

  ll ret = 0LL;

  ret += div * window / 2;

  if (mod * 2 > window) {
    ret += mod - (window / 2);
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &a, &b);

  n = int(ceil(log2(b))) + 1;

  ans = 0LL;

  for (int i = 0; i <= n; ++i) {
    ll base = 1LL << i;

    ll cnt = calc(i, b) - calc(i, a - 1);

    ans += base * (cnt % 2);
  }

  printf("%lld\n", ans);

  return 0;
}
