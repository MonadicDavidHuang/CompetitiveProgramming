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

ll n, k;

double ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &k);

  for (ll i = 1; i <= n; ++i) {
    ll kdivi = k / i;
    ll around = log2(kdivi);

    ll times;

    for (ll j = around; j <= around + 1; ++j) {
      if (i * mypow(2, j) >= k) {
        times = j;
        break;
      }
    }

    double bottom = mypow(2, times);

    ans += 1.0 / bottom;
  }

  ans /= (double)(n);

  printf("%.10lf\n", ans);

  return 0;
}
