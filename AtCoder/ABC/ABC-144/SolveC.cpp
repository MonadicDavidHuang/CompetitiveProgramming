#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e13 + 5);

ll n;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ll ans = INF;

  for (ll i = 1L; i * i <= n; ++i) {
    if (n % i != 0) continue;

    ll other = n / i;

    ans = min(ans, i - 1 + other - 1);
  }

  printf("%lld\n", ans);

  return 0;
}
