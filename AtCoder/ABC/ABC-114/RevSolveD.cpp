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

ll n;

map<ll, ll> cnt_base;
map<ll, ll> cnt;
map<ll, ll> cnt_acc;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  for (ll i = 1LL; i <= n; ++i) {
    for (auto &e : prime_factorization(i)) {
      cnt_base[e.first] += e.second;
    }
  }

  for (auto &e : cnt_base) {
    cnt[e.second] += 1LL;
  }

  ll whole = 0;

  for (auto &e : cnt) {
    whole += e.second;
  }

  for (auto &e : cnt) {
    cnt_acc[e.first] = whole;
    whole -= e.second;
  }

  ans = 0LL;

  ll p_74 = 0LL;
  auto ptr = cnt_acc.lower_bound(74);
  if (ptr != cnt_acc.end()) {
    p_74 = ptr->second;
  }

  ll p_2 = 0LL;
  ptr = cnt_acc.lower_bound(2);
  if (ptr != cnt_acc.end()) {
    p_2 = ptr->second;
  }
  ll p_24 = 0LL;
  ptr = cnt_acc.lower_bound(24);
  if (ptr != cnt_acc.end()) {
    p_24 = ptr->second;
  }

  ll p_4 = 0LL;
  ptr = cnt_acc.lower_bound(4);
  if (ptr != cnt_acc.end()) {
    p_4 = ptr->second;
  }
  ll p_14 = 0LL;
  ptr = cnt_acc.lower_bound(14);
  if (ptr != cnt_acc.end()) {
    p_14 = ptr->second;
  }

  ans += p_74;

  ans += p_24 * max(p_2 - 1LL, 0LL);

  ans += p_14 * max(p_4 - 1LL, 0LL);

  ans += p_4 * max(p_4 - 1LL, 0LL) * max(p_2 - 2LL, 0LL) / 2LL;

  printf("%lld\n", ans);

  return 0;
}
