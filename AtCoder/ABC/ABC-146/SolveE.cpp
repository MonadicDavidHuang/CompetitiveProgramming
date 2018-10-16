#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll k;
ll a[MAX_N];

ll acc[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + a[i];
  }

  ll ans = 0LL;

  unordered_map<ll, ll> cnt;

  cnt[0LL] = 1LL;

  for (int i = 1; i <= n; ++i) {
    ll lli = (ll)(i);

    ll last = lli - k;
    if (last >= 0LL) {
      ll remove = (acc[int(last)] - last) % k;
      cnt[remove] -= 1LL;
    }

    ll target = (acc[i] - lli) % k;

    ans += cnt[target];

    cnt[target] += 1LL;
  }

  printf("%lld\n", ans);

  return 0;
}
