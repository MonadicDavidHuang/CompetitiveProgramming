#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

unordered_map<char, ll> cnt;

int main(void) {
  // Here your code !
  cin >> s;

  for (auto &e : s) {
    cnt[e] += 1L;
  }

  ll n = s.size();

  ll ans = 1L + n * (n - 1L) / 2L;

  for (auto &e : cnt) {
    ll subtract = e.second * (e.second - 1L) / 2L;
    ans -= subtract;
  }

  printf("%lld\n", ans);

  return 0;
}
