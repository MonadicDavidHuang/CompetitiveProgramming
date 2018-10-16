#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e17 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  ll whole = 0LL;

  for (int i = 0; i < n; ++i) {
    whole += a[i];
  }

  ll cur = 0LL;

  ll diff = INF;
  int index = -1;

  for (int i = 0; i < n; ++i) {
    cur += a[i];

    ll other = whole - cur;

    if (abs(other - cur) < diff) {
      index = i;
      diff = abs(other - cur);
    }
  }

  ll ans = diff;

  printf("%lld\n", ans);

  return 0;
}
