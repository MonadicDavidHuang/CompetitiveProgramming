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

bool check(ll x) {
  ll tmp_k = k;

  for (int i = 0; i < n; ++i) {
    ll aifi = a[i] * f[i];

    if (aifi <= x) continue;  // already satisfied

    if (tmp_k == 0 && aifi > x) return false;

    ll times = ((aifi - x) - 1) / f[i] + 1L;

    ll actual_times = min(times, tmp_k);

    aifi -= actual_times *
            f[i];  // sum_i ((ai - ki) x fi_ = sum_i (ai x fi - ki x fi)
    tmp_k -= actual_times;

    if (aifi > x) {
      return false;
    }
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

  sort(a, a + n);
  sort(f, f + n, greater<ll>());

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
