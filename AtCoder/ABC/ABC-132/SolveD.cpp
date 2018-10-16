#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e4 + 5);
const ll MOD = (ll)(1e9 + 7);

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

int n, k;

CombinationModulo cm(MAX_N);

ll calc(int cur_k) {
  ll base = cm.comb(n - k + 1, cur_k);

  ll remain = (ll)(k - cur_k);

  ll add = cm.comb(cur_k + remain - 1, remain);

  return (base * add) % MOD;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= k; ++i) {
    printf("%lld\n", calc(i));
  }

  return 0;
}
