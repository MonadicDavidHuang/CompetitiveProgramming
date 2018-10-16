#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ll ans = (n - 1 + 1) * (n - 1) / 2LL;

  printf("%lld\n", ans);

  return 0;
}
