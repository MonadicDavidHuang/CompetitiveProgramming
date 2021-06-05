#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const ll INF = (ll)(1e10 + 5);

const ll MAX = (ll)(2e5 + 5);
const ll mult = (ll)(1e4);

double xd, yd, rd;

ll x, y, r;

bool check(ll next, ll width_2_pow) {
  return next * next <= width_2_pow;
}

ll mod_floor(ll right, ll mod) {
  if (right >= 0) {
    return right - (right % mod);
  } else {
    return right - (right % mod) - ((right % mod) == 0LL ? 0LL : mod);
  }
}

ll mod_ceil(ll left, ll mod) {
  if (left >= 0) {
    return left - (left % mod) + ((left % mod) == 0LL ? 0LL : mod);
  } else {
    return left - (left % mod);
  }
}

ll count_for(ll length) {
  ll width_2_pow = r * r - length * length;

  ll ok = 0LL;
  ll ng = MAX * mult;

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2LL;
    if (check(next, width_2_pow))
      ok = next;
    else
      ng = next;
  }

  ll left = mod_ceil(x - ok, mult);
  ll right = mod_floor(x + ok, mult);

  return (right - left) / mult + 1LL;
}

int main(void) {
  // Here your code !
  scanf("%lf %lf %lf", &xd, &yd, &rd);

  x = (ll)(round(xd * (double)(mult)));
  y = (ll)(round(yd * (double)(mult)));
  r = (ll)(round(rd * (double)(mult)));

  ll bottom = mod_ceil(y - r, mult);
  ll top = mod_floor(y + r, mult);

  ll ans = 0LL;

  for (ll i = bottom; i <= top; i += mult) {
    ans += count_for(abs(y - i));
  }

  printf("%lld\n", ans);

  return 0;
}
