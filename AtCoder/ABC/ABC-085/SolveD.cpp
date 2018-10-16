#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll h;

ll a[MAX_N], b[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &h);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(a[i]), &(b[i]));
  }

  ll max_a = -1LL;

  for (int i = 0; i < n; ++i) {
    max_a = max(max_a, a[i]);
  }

  sort(b, b + n, greater<ll>());

  ll cnt = 0LL;
  ll dmg = 0LL;

  for (int i = 0; i < n; ++i) {
    if (b[i] <= max_a) break;

    cnt += 1LL;

    dmg += b[i];

    if (dmg >= h) break;
  }

  ll ans;
  if (dmg >= h) {
    ans = cnt;
  } else {
    ll remain = h - dmg;

    cnt += (remain - 1LL + max_a) / max_a;

    ans = cnt;
  }

  printf("%lld\n", ans);

  return 0;
}
