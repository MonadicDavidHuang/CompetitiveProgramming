#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e12 + 5);

ll n, h;
ll a, b, c, d, e;

ll ans;

bool check(ll cd_times, ll remain_days, ll basic) {
  if (cd_times >= remain_days) return true;

  ll cd_gain = cd_times * d;

  ll total = cd_gain + basic - e * (remain_days - cd_times);

  return (total > 0);
}

// return minimum money where use times of pair of (a, b) fixed
ll calc(int ab_times) {
  if (ab_times >= n) {
    return ab_times * a;
  }

  ll basic = ab_times * b + h;

  ll remain_days = n - ab_times;

  if (basic - remain_days * e > 0) {
    return ab_times * a;
  }

  ll ng = 0;
  ll ok = remain_days + remain_days;

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2;
    if (check(next, remain_days, basic)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  return ab_times * a + ok * c;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &h);
  scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);

  ans = INF;

  for (ll i = 0; i <= n; ++i) {
    ans = min(ans, calc(i));
  }

  printf("%lld\n", ans);

  return 0;
}
