#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e4 + 5);
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

/////////////////////////////////////////////////////////////
map<ll, ll> prime_factorization(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res[i] += 1;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}
/////////////////////////////////////////////////////////////

int n;
ll a[MAX_N];

ModuloOperator mo(MOD);

void update_lcm(unordered_map<ll, ll>& lcm, ll target) {
  auto primes = prime_factorization(target);

  for (auto& e : primes) {
    lcm[e.first] = max(lcm[e.first], e.second);
  }
}

ll calc_actual(unordered_map<ll, ll>& lcm) {
  ll ret = 1LL;

  for (auto& e : lcm) {
    ll power = mo.pow(e.first, e.second);

    ret = mo.mul(ret, power);
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  unordered_map<ll, ll> lcm;

  for (int i = 0; i < n; ++i) {
    update_lcm(lcm, a[i]);
  }

  ll ans = 0LL;

  ll lcm_actual = calc_actual(lcm);

  for (int i = 0; i < n; ++i) {
    ans = mo.add(ans, mo.div(lcm_actual, a[i]));
  }

  printf("%lld\n", ans);

  return 0;
}
