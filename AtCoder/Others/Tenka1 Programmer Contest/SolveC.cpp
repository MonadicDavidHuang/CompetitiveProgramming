#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MAX_NUM = (ll)(3e3 + 500);

ll m;

tuple<ll, ll, ll> solve() {
  for (ll h = 1; h <= MAX_NUM; ++h) {
    for (ll n = 1; n <= MAX_NUM; ++n) {
      ll top = m * h * n;
      ll bottom = 4 * h * n - m * n - m * h;

      // printf("h: %d, n: %d, top: %d, bottom: %d\n", h, n, top, bottom);

      if (bottom == 0) continue;
      if (top < 1) continue;

      if (top % bottom != 0) continue;

      ll w = top / bottom;

      if (w < 1) continue;

      return make_tuple(h, n, top / bottom);
    }
  }

  return make_tuple(-1LL, -1LL, -1LL);
}

int main(void) {
  // Here your code !
  scanf("%lld", &m);

  auto ans = solve();

  printf("%lld %lld %lld\n", get<0>(ans), get<1>(ans), get<2>(ans));

  return 0;
}
