#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
ll t[MAX_N];

ll perm[MAX_N];

ll acc[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(t[i]));
  }

  perm[1] = 1LL % MOD;
  for (int i = 2; i <= n; ++i) {
    perm[i] = (i * perm[i - 1]) % MOD;
  }

  unordered_map<int, int> cnt;

  for (int i = 1; i <= n; ++i) {
    cnt[t[i]] += 1;
  }

  sort(t + 1, t + 1 + n);

  ll pat = 1LL;

  for (auto &e : cnt) {
    pat *= perm[e.second];
    pat %= MOD;
  }

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + t[i];
  }

  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    ans += acc[i];
  }

  printf("%lld\n", ans);

  printf("%lld\n", pat);

  return 0;
}
