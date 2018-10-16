#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);
const int MAX_M = (int)(2e3 + 5);

const ll MOD = (ll)(1e9 + 7);

int n, m;

int s[MAX_N], t[MAX_M];

ll dp[MAX_N][MAX_M];

ll acc[MAX_N][MAX_M];

ll ans;

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

ModuloOperator mo(MOD);

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(s[i]));
  }

  for (int i = 1; i <= m; ++i) {
    scanf("%d", &(t[i]));
  }

  for (int i = 0; i <= n; ++i) acc[i][0] = 1LL;
  for (int i = 0; i <= m; ++i) acc[0][i] = 1LL;

  dp[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = (s[i] == t[j]) ? acc[i - 1][j - 1] : 0LL;
      acc[i][j] = mo.add(
          mo.sub(mo.add(acc[i - 1][j], acc[i][j - 1]), acc[i - 1][j - 1]),
          dp[i][j]);
    }
  }

  ans = acc[n][m];

  printf("%lld\n", ans);

  return 0;
}
