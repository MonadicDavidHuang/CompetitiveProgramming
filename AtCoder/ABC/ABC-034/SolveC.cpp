#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int w, h;

ll ans;

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

int main(void) {
  // Here your code !
  scanf("%d %d", &w, &h);

  CombinationModulo comb_mod(w + h);

  ans = comb_mod.comb(w + h - 2, w - 1);

  printf("%lld\n", ans);

  return 0;
}
