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

ll n, k;

ll ans;

ModuloOperator mo(MOD);

vector<ll> calc_divisors(ll k) {
  vector<ll> ret;

  for (ll i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      ret.push_back(i);
      if (i * i != k) {
        ret.push_back(k / i);
      }
    }
  }

  return ret;
}

vector<ll> calc_prime_factors(ll k) {
  auto mp = prime_factorization(k);

  vector<ll> ret;

  for (auto &e : mp) {
    ret.push_back(e.first);
  }

  return ret;
}

ll lcm_rush(ll n, ll k) {
  auto prime_factors = calc_prime_factors(k);

  ll ret = 0LL;

  ret += mo.div(mo.mul(mo.add(1LL, n), n), 2LL);

  ll minus = 0LL;

  int size = prime_factors.size();

  for (int i = 1; i < 1 << size; ++i) {
    int bit_cnt = 0;
    ll val = 1LL;

    for (int j = 0; j < size; ++j) {
      if (i >> j & 1) {
        val = mo.mul(val, prime_factors[j]);
        bit_cnt += 1;
      }
    }

    ll nums = n / val;

    ll s = val;

    ll t = mo.mul(val, nums);

    ll part = mo.div(mo.mul(mo.add(s, t), nums), 2LL);

    if (bit_cnt % 2 == 0)
      minus = mo.sub(minus, part);
    else
      minus = mo.add(minus, part);
  }

  ret = mo.sub(ret, minus);

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &k);

  auto divisors = calc_divisors(k);

  ans = 0LL;

  for (auto divisor : divisors) {
    ll tmp = mo.mul(lcm_rush(n / divisor, k / divisor), k);

    ans = mo.add(ans, tmp);
  }

  printf("%lld\n", ans);

  return 0;
}
