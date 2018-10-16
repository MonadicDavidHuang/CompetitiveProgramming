#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
ll t;

ll ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &t);

  ll last;
  scanf("%lld", &last);

  for (int i = 1; i < n; ++i) {
    ll cur;
    scanf("%lld", &cur);
    ans += min(cur - last, t);
    last = cur;
  }

  ans += t;

  printf("%lld\n", ans);

  return 0;
}
