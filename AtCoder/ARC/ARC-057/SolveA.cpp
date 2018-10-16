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

const ll TARGET = (ll)(2e12);

ll a, k;

ll ans;

ll calc(int day) {
  ll cur_pow = mypow(k, day);
  return (1LL - cur_pow) / (1LL - k) + cur_pow * a;
}

bool check(int next) { return calc(next) >= TARGET; }

int main(void) {
  // Here your code !
  scanf("%lld %lld", &a, &k);

  if (k == 0) {
    ans = TARGET - a;
  } else {
    ll cur = a;

    for (int i = 1;; ++i) {
      cur += 1LL + k * cur;
      if (cur >= TARGET) {
        ans = i;
        break;
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
