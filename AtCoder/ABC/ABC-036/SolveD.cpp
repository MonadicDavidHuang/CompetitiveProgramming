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

ModuloOperator mo(MOD);

map<pair<int, char>, ll> memo;

int n;
vector<vector<int>> graph(MAX_N);

ll paint(int parent, int cur, char col) {
  auto key = make_pair(cur, col);

  if (memo.find(key) != memo.end()) {
    return memo[key];
  }

  ll ret = 1LL;

  if (col == 'b') {
    for (auto &next : graph[cur]) {
      if (next == parent) continue;
      ret = mo.mul(ret, paint(cur, next, 'w'));
    }
  } else {  // col == 'w'
    for (auto &next : graph[cur]) {
      if (next == parent) continue;
      ll tmp = 1LL;
      tmp = mo.add(paint(cur, next, 'b'), paint(cur, next, 'w'));
      ret = mo.mul(ret, tmp);
    }
  }

  return memo[key] = ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  ll ans = mo.add(paint(0, 1, 'w'), paint(0, 1, 'b'));

  printf("%lld\n", ans);

  return 0;
}
