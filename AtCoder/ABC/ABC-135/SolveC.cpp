#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];
ll b[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(b[i]));
  }

  ans = 0LL;

  for (int i = n - 1; i >= 0; --i) {
    ll tmp = min(b[i], a[i + 1]);

    ans += tmp;

    a[i + 1] -= tmp;
    b[i] -= tmp;

    if (b[i] == 0) continue;

    tmp = min(b[i], a[i]);

    ans += tmp;

    a[i] -= tmp;
    // b[i] -= tmp;
  }

  printf("%lld\n", ans);

  return 0;
}
