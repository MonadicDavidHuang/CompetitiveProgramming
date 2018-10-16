#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_R = (int)(30 + 5);

const ll MOD = (ll)(1e9 + 7);

int r, c, x, y, d, l;

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

ll calc(int x, int y, int d, int l, CombinationModulo& comb_mod) {
  ll ret = 0;

  for (int i = 0; i < (1 << 4); ++i) {
    int cx = x, cy = y;
    int cnt = 0;

    if ((i >> 0) & 1) {
      cy -= 1;
      cnt += 1;
    }

    if ((i >> 1) & 1) {
      cx -= 1;
      cnt += 1;
    }

    if ((i >> 2) & 1) {
      cy -= 1;
      cnt += 1;
    }

    if ((i >> 3) & 1) {
      cx -= 1;
      cnt += 1;
    }

    if (cx <= 0 || cy <= 0 || cx * cy < d + l) continue;

    ll tmp_d = comb_mod.comb(cx * cy, d) % MOD;
    ll tmp_l = comb_mod.comb(cx * cy - d, l) % MOD;
    ll tmp = tmp_d * tmp_l % MOD;

    if (cnt % 2 == 1) {
      ret -= tmp;
      ret += MOD;
    } else {
      ret += tmp;
    }

    ret %= MOD;
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &r, &c);
  scanf("%d %d", &x, &y);
  scanf("%d %d", &d, &l);

  int a = r - x + 1;
  int b = c - y + 1;

  CombinationModulo comb_mod(MAX_R * MAX_R);

  ans = 1LL;
  ans *= a * b % MOD;

  if (d + l == x * y) {
    ans *= comb_mod.comb(d + l, d);
  } else {
    ans *= calc(x, y, d, l, comb_mod);
  }

  ans %= MOD;

  printf("%lld\n", ans);

  return 0;
}
