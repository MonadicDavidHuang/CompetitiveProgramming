#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;
ll k;

ll count(string t) {
  ll cnt = 0LL;

  t.push_back('_');

  ll cur = 1LL;
  for (int i = 1; i < t.size(); ++i) {
    if (t[i] == t[i - 1]) {
      cur += 1LL;
    } else {
      cnt += cur / 2LL;
      cur = 1LL;
    }
  }

  return cnt;
}

int main(void) {
  // Here your code !
  cin >> s;
  scanf("%lld", &k);

  ll ans = count(s) * k;

  string tmp(s.size(), s[0]);

  if (tmp == s) {
    printf("%lld\n", (ll)(s.size()) * k / 2LL);
    return 0;
  }

  if (s[0] == s.back()) {
    char target = s[0];

    ll a = 0LL;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != target) break;
      a += 1LL;
    }

    ll b = 0LL;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != target) break;
      b += 1LL;
    }

    ll connect_part = (a + b) / 2LL - (a / 2LL + b / 2LL);

    ans += connect_part * (k - 1LL);
  }

  printf("%lld\n", ans);

  return 0;
}
