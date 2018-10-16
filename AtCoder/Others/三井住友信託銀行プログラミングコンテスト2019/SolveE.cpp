#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
ll a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  unordered_map<ll, ll> cnt;

  cnt[0LL] = 3LL;

  ll ans = 1LL;

  for (int i = 1; i <= n; ++i) {
    if (cnt.find(a[i]) == cnt.end()) {
      ans = 0LL;
      break;
    }

    ans *= cnt[a[i]];
    ans %= MOD;

    cnt[a[i]] -= 1LL;
    cnt[a[i] + 1LL] += 1LL;
  }

  printf("%lld\n", ans);

  return 0;
}
