#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll s;

ll a, b, c, d, e, f;

int main(void) {
  // Here your code !
  scanf("%lld", &s);

  e = 0LL;
  f = 0LL;

  a = (ll)(1e9);
  c = 1LL;

  ll div = s / a;
  ll mod = s % a;

  if (mod == 0LL) {
    d = div;
    b = 0LL;
  } else {
    d = div + 1LL;
    b = a - mod;
  }

  printf("%lld %lld %lld %lld %lld %lld\n", a, b, c, d, e, f);

  return 0;
}
