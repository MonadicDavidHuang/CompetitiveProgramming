#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n, k;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &k);

  ans = 0LL;

  for (ll i = 1LL; i <= n; ++i) {
    ll block = (n + 1LL) / i;
    ll remain = (n + 1LL) % i;

    ll commit_block = max(i - k, 0LL);
    ll commit_remain = max(remain - k, 0LL);

    ans += commit_block * block + commit_remain - ((k == 0LL) ? 1LL : 0LL);
  }

  printf("%lld\n", ans);

  return 0;
}
