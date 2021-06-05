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

map<tuple<ll, ll, ll>, ll> memo;

ll calc(ll p, ll z, ll visited) {
  auto key = make_tuple(p, z, visited);
  if (memo.find(key) != memo.end()) return memo[key];

  if (z == 0) return memo[key] = 0LL;

  ll best = -1LL;
  for (ll i = 1; i <= z; ++i) {
    if (visited >> int(i)) continue;

    visited = visited | 1 << int(i);
    best = max(best, calc(p, z - i, visited));
    visited = visited & (~(1 << int(i)));
  }

  return memo[key] = best + 1LL;
}

ll n;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  auto pfd = prime_factorization(n);

  ll ans = 0LL;

  for (auto e : pfd) {
    ll visited = 0LL;
    ans += calc(e.first, e.second, visited);
  }

  printf("%lld\n", ans);

  return 0;
}
