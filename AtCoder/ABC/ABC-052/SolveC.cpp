#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);

ll x;

map<ll, ll> cnt;

ll ans;

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

int main(void) {
  // Here your code !
  scanf("%lld", &x);

  for (int i = 2; i <= x; ++i) {
    for (auto &e : prime_factorization(i)) {
      if (cnt.find(e.first) != cnt.end()) {
        cnt[e.first] += e.second;
      } else {
        cnt[e.first] = e.second;
      }
    }
  }

  ans = 1;
  for (auto &e : cnt) {
    ans = ans * ((e.second + 1) % MOD);
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
