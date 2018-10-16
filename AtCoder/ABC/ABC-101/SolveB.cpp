#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

ll m;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  m = n;

  ans = 0LL;

  ll base = (ll)(1e9);

  for (int i = 0; i < 10; ++i) {
    ll tmp = n / base;
    n -= tmp * base;
    ans += tmp;
    if (base == 1LL) break;
    base /= 10LL;
  }

  if (m % ans == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
