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

ll n, k;

ModuloOperator mo(MOD);

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &k);

  vector<pair<ll, ll>> s;

  for (ll i = 1; i * i <= n; ++i) {
    s.emplace_back(i, 0LL);
    s.emplace_back(n / i, 0LL);
  }

  sort(s.begin(), s.end());

  s.erase(unique(s.begin(), s.end()), s.end());

  for (int i = 0; i < s.size() - 1; ++i) {
    ll left = n / s[i + 1].first;
    ll right = n / s[i].first;
    s[i].second = right - left;
  }
  s.back().second = 1;

  int m = s.size();

  map<ll, int> factor2ind;
  for (int i = 0; i < m; ++i) {
    factor2ind[s[i].first] = i;
  }

  vector<vector<ll>> dp(k + 1, vector<ll>(m));

  dp[0][factor2ind[n]] = 1LL;

  for (int i = 0; i < k; ++i) {
    for (int j = m - 2; j >= 0; --j) dp[i][j] = mo.add(dp[i][j], dp[i][j + 1]);
    for (int j = 0; j < m; ++j) {
      int coj = factor2ind[n / s[j].first];
      dp[i + 1][j] = mo.add(dp[i + 1][j], mo.mul(dp[i][coj], s[j].second));
    }
  }

  ll ans = 0LL;

  for (int i = 0; i < m; ++i) {
    ans = mo.add(ans, dp[k][i]);
  }

  printf("%lld\n", ans);

  return 0;
}
