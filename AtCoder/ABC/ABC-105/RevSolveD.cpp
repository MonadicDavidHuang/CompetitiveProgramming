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
map<ll, ll> cnt;
map<ll, ll> tmp_cnt;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + a[i];
  }

  for (int i = 0; i <= n; ++i) {
    acc[i] %= m;
    cnt[acc[i]] += 1LL;
  }

  ans = 0LL;

  for (int i = 0; i < n; ++i) {
    tmp_cnt[acc[i]] += 1LL;

    ll cur_key = acc[i];

    ans += cnt[cur_key] - tmp_cnt[cur_key];
  }

  printf("%lld\n", ans);

  return 0;
}
