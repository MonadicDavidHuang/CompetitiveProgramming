#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
ll mypow_core(ll x, int n, ll result) {
  if (n == 0) {
    return result;
  }

  if (n % 2 == 0) {
    return mypow_core(x * x, n / 2, result);
  } else {
    return mypow_core(x, n - 1, x * result);
  }
}

ll mypow(ll x, int n) { return mypow_core(x, n, 1); }
/////////////////////////////////////////////////////////////

const int MAX_N = (int)(1e3 + 5);

int n, k;

ll a[MAX_N];

bool check(ll target, int m) {
  int cnt = 0;

  ll hope = target + mypow(2LL, m);

  for (int i = 0; i < n; ++i) {
    ll tmp = 0LL;
    for (int j = i; j < n; ++j) {
      tmp += a[j];

      cnt += ((hope & tmp) == hope) ? 1 : 0;
    }
  }

  return cnt >= k;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  ll ans = 0LL;

  for (int i = 40 + 3; i >= 0; --i) {
    if (check(ans, i)) {
      ans += mypow(2LL, i);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
