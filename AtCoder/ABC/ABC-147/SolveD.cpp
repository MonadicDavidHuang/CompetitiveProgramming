#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
class ModuloOperator {
 public:
  ll modulo;

  ModuloOperator(ll modulo) { this->modulo = modulo; }

  ll add(ll a, ll b) {
    ll ret = a + b;
    ret %= modulo;
    return ret;
  }

  ll sub(ll a, ll b) {
    ll ret = a - b;
    if (ret < 0)
      ret += modulo;
    else
      ret %= modulo;
    return ret;
  }

  ll mul(ll a, ll b) {
    ll ret = a * b;
    ret %= modulo;
    return ret;
  }

  ll div(ll a, ll b) { return mul(a, pow(b, modulo - 2)); }

  ll pow(ll x, ll y) {
    ll res = 1LL;

    x %= modulo;

    while (y > 0) {
      if (y & 1) {
        res = mul(res, x);
      }

      y = y >> 1;
      x = mul(x, x);
    }

    return res;
  }
};
/////////////////////////////////////////////////////////////

const int MAX_N = (int)(3e5 + 5);
const int MAX_LOG = (int)(6e1 + 1);
const ll MOD = (ll)(1e9 + 7);

int n;
ll a[MAX_N];

int cnt[MAX_N];

ModuloOperator mo(MOD);

void add_to_cnt(ll t) {
  for (int i = 0; i < MAX_LOG; ++i) {
    if (t >> i & 1LL) cnt[i] += 1;
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  ll ans = 0LL;

  add_to_cnt(a[0]);

  for (int i = 1; i < n; ++i) {
    ll tmp = a[i];

    ll base = 1LL;

    for (int j = 0; j < MAX_LOG; ++j) {
      int oz = (tmp >> j & 1LL) ? 1 : 0;
      ll times = oz == 1 ? i - cnt[j] : cnt[j];
      ll commit = mo.mul(base, times);

      ans = mo.add(ans, commit);
      base = mo.mul(base, 2LL);
    }

    add_to_cnt(a[i]);
  }

  printf("%lld\n", ans);

  return 0;
}
