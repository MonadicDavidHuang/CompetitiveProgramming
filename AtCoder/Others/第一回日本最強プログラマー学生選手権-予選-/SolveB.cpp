#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
ll k;
int a[MAX_N];

ll base[MAX_N];
ll duplicate[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) base[i] += 1LL;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (a[i] > a[j]) duplicate[i] += 1LL;
    }
  }

  ll coef = k * (k - 1LL) / 2LL;
  coef %= MOD;

  ans = 0LL;

  for (int i = 0; i < n; ++i) {
    ans += k * base[i];
    ans %= MOD;

    ans += coef * duplicate[i];
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
