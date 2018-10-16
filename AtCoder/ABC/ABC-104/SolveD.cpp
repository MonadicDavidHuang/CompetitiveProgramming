#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
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

string s;

int n;
ll cnt_a[MAX_N];
ll cnt_c[MAX_N];
ll cnt_q[MAX_N];

ModuloOperator mo(MOD);

ll ans;

int main(void) {
  // Here your code !
  cin >> s;

  n = s.size();

  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'A') cnt_a[i] = 1LL;
    if (s[i - 1] == 'C') cnt_c[i] = 1LL;
    if (s[i - 1] == '?') cnt_q[i] = 1LL;
  }

  for (int i = 1; i <= n; ++i) {
    cnt_a[i] += cnt_a[i - 1];
    cnt_c[i] += cnt_c[i - 1];
    cnt_q[i] += cnt_q[i - 1];
  }

  ans = 0LL;

  for (int i = 2; i < n; ++i) {
    int ind = i - 1;
    if (s[ind] == 'A' || s[ind] == 'C') continue;

    ll left_a = cnt_a[i - 1];
    ll right_c = cnt_c[n] - cnt_c[i];
    ll left_q = cnt_q[i - 1];
    ll right_q = cnt_q[n] - cnt_q[i];

    ll tmp_left = 0LL;
    tmp_left += mo.mul(left_a, mo.pow(3LL, left_q));
    tmp_left += mo.mul(left_q, mo.pow(3LL, max(left_q - 1LL, 0LL)));

    ll tmp_right = 0LL;
    tmp_right += mo.mul(right_c, mo.pow(3LL, right_q));
    tmp_right += mo.mul(right_q, mo.pow(3LL, max(right_q - 1LL, 0LL)));

    ans = mo.add(ans, mo.mul(tmp_left, tmp_right));
  }

  printf("%lld\n", ans);

  return 0;
}
