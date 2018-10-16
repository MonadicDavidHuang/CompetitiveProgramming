#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll k;
ll a[MAX_N];

ll acc[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + a[i];
  }

  ans = 0;

  for (int i = 0; i <= n; ++i) {
    ll *tmp = lower_bound(acc + i, acc + n + 1, acc[i] + k);

    int pos = tmp - acc;

    if (pos == n + 1) continue;  // not found

    int diff = (acc + n) - tmp;

    ans += diff + 1;
  }

  printf("%lld\n", ans);

  return 0;
}
