#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);

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

ll d, e, f;

ModuloOperator mo(MOD);

int main(void) {
  // Here your code !
  scanf("%lld", &d);
  scanf("%lld", &e);
  scanf("%lld", &f);

  ll alpha = mo.mul(mo.div(e, f), mo.sub(mo.div(f, d), 1));
  ll beta = mo.mul(mo.div(f, e), mo.sub(mo.div(e, d), 1));

  ll c = mo.div(alpha, mo.sub(1, alpha));
  ll r = mo.div(beta, mo.sub(1, beta));

  printf("%lld %lld\n", r, c);

  return 0;
}
