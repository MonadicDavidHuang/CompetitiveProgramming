#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

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

/////////////////////////////////////////////////////////////
class CombinationModulo {
 public:
  static const ll MOD = (ll)(1e9 + 7);

  vector<ll> fact;
  vector<ll> inv;
  vector<ll> fact_inv;

  CombinationModulo(int n) {
    this->fact = vector<ll>(n + 1, 0LL);
    this->inv = vector<ll>(n + 1, 0LL);
    this->fact_inv = vector<ll>(n + 1, 0LL);
    init(n);
  }

  void init(int n) {
    inv[1] = fact[0] = fact_inv[0] = 1LL;
    for (int i = 2; i <= n; i++) {
      inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i % MOD;
    }
    for (int i = 1; i <= n; i++) {
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
  }

  ll comb(int n, int r) {
    if (r > n) return 0LL;
    return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
  }
};
/////////////////////////////////////////////////////////////

const ll MOD = (ll)(1e9 + 7);

int n;
ll m;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &m);

  auto prime_map = prime_factorization(m);

  int max_sholder = -1;

  for (auto &e : prime_map) {
    max_sholder = max(max_sholder, (int)(e.second));
  }

  CombinationModulo cm(n + max_sholder + 3);

  ans = 1LL;

  for (auto &e : prime_map) {
    ll cur = cm.comb(n + (int)(e.second) - 1, (int)(e.second));
    ans *= cur;
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
