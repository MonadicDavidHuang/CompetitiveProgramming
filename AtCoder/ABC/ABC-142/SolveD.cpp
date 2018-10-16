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

ll a, b;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &a, &b);

  auto cand_a = prime_factorization(a);

  auto cand_b = prime_factorization(b);

  map<ll, ll> merge;

  int ans = 1;

  for (auto &e : cand_a) {
    auto ptr = cand_b.find(e.first);

    if (ptr == cand_b.end()) continue;

    ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
