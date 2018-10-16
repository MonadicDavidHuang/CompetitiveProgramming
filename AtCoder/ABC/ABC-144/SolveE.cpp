#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e13 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll k;

ll a[MAX_N];
ll f[MAX_N];

ll aifi[MAX_N];

bool check(ll x) {
  ll tmp_k = k;

  for (int i = 0; i < n; ++i) {
    ll aifi = a[i] * f[i];

    if (aifi <= x) continue;

    if (tmp_k == 0 && aifi > x) return false;

    ll diff = aifi - x;
    ll times = (diff - 1L) / f[i] + 1L;
    ll actual = min(times, tmp_k);

    aifi -= f[i] * actual;

    tmp_k -= actual;

    if (aifi > x) return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(f[i]));
  }

  if (n == 1) {
    ll ans = (a[0] - min(a[0], k)) * f[0];
    printf("%llf\n", ans);
    return 0;
  }

  sort(a, a + n);

  sort(f, f + n);
  reverse(f, f + n);

  ll ok = INF;
  ll ng = -1L;

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2L;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  ll ans = ok;

  printf("%lld\n", ans);

  return 0;
}
