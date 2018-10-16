#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
ll b[MAX_N];

ll a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n - 1; ++i) {
    a[i] = INF;
    scanf("%lld", &(b[i]));
  }

  for (int i = 1; i <= n; ++i) {
    a[i] = INF;
  }

  for (int i = 1; i <= n - 1; ++i) {
    a[i] = min(a[i], b[i]);
    a[i + 1] = min(a[i + 1], b[i]);
  }

  ll ans = 0LL;

  for (int i = 1; i <= n; ++i) {
    ans += a[i];
  }

  printf("%lld\n", ans);

  return 0;
}
