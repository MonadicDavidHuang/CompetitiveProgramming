#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////

ll a, b, c, d;

ll cd_lcm;

ll ans;

ll calc(ll x) { return x - (x / c + x / d - x / cd_lcm); }

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

  cd_lcm = c * d / gcd(c, d);

  ans = calc(b) - calc(a - 1);

  printf("%lld\n", ans);

  return 0;
}
