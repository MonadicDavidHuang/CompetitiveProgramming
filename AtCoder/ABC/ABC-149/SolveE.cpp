#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll m;

ll a[MAX_N];

ll acc[MAX_N];

bool check(ll x) {
  ll count = 0LL;

  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(a, a + n, x - a[i]) - a;
    count += (ll)(n - idx);
  }

  return count >= m;
}

int main(void) {
  // Here your code !

  scanf("%d %lld", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  sort(a, a + n);

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + a[i - 1];
  }

  ll ok = 0;
  ll ng = 2LL * (ll)(1e5 + 3);

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  ll ans = 0LL;
  ll count = 0LL;

  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(a, a + n, ok - a[i]) - a;

    ll length = (ll)(n - idx);

    ans += a[i] * length + acc[n] - acc[idx + 1 - 1];
    count += length;
  }

  ans -= abs(m - count) * ok;

  printf("%lld\n", ans);

  return 0;
}
