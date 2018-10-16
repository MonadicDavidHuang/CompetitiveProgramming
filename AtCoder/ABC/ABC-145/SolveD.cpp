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

const ll MOD = (ll)(1e9 + 7);

ModuloOperator mo(MOD);

ll x, y;

pair<ll, ll> do_convert(ll bx, ll by) {
  ll nx = 2LL * bx + (-1LL) * by;
  ll ny = (-1LL) * bx + 2LL * by;

  return make_pair(nx, ny);
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &x, &y);

  auto nxy = do_convert(x, y);

  ll nx = nxy.first;
  ll ny = nxy.second;

  if (nx < 0 || ny < 0 || nx % 3LL != 0 || ny % 3LL != 0) {
    printf("0\n");
    return 0;
  }

  nx /= 3LL;
  ny /= 3LL;

  ll n = nx + ny;

  ll top = 1LL;
  for (ll i = 1LL; i <= n; ++i) {
    top = mo.mul(top, i);
  }

  ll gnx = 1LL;
  for (ll i = 1LL; i <= nx; ++i) {
    gnx = mo.mul(gnx, i);
  }

  ll gny = 1LL;
  for (ll i = 1LL; i <= ny; ++i) {
    gny = mo.mul(gny, i);
  }

  ll bottom = mo.mul(gnx, gny);

  ll ans = mo.div(top, bottom);

  printf("%lld\n", ans);

  return 0;
}
