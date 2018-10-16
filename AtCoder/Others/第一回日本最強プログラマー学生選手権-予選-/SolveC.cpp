#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);

ll n;
string s;

string d;

int main(void) {
  // Here your code !
  scanf("%lld", &n);
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    if (i % 2 == 0) s[i] = (s[i] == 'W') ? 'B' : 'W';
  }

  for (auto &e : s) {
    d.push_back((e == 'B') ? 'R' : 'L');
  }

  int cnt_l = 0;
  int cnt_r = 0;

  for (auto &e : d) {
    cnt_l += (e == 'L') ? 1 : 0;
    cnt_r += (e == 'R') ? 1 : 0;
  }

  if (cnt_l != cnt_r) {
    printf("0\n");
    return 0;
  }

  ll ans = 1LL;

  ll cur_l = 0LL;
  ll cur_r = 0LL;

  for (auto &e : d) {
    if (e == 'R') {
      ans *= cur_l - cur_r;
      ans %= MOD;

      cur_r += 1LL;
    } else {
      cur_l += 1LL;
    }
  }

  for (ll i = 1LL; i <= n; ++i) {
    ans *= i;
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
