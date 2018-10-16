#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  int n = s.size() + 1;

  vector<ll> base(n, -1L);

  if (s[0] == '<') base[0] = 0;

  if (s.back() == '>') base[n - 1] = 0;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i - 1] == '>' && s[i] == '<') {
      base[i] = 0;
    }
  }

  s.insert(0, s[0] == '<' ? "_" : ">");

  for (int i = 0; i < n; ++i) {
    if (base[i] != 0) continue;

    for (int j = i + 1; j < n; ++j) {
      if (s[j] == '>') break;
      base[j] = (ll)(j - i);
    }

    for (int j = i - 1; j >= 0; --j) {
      if (s[j] == '<') break;
      base[j] = (ll)(i - j);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '<' && s[i + 1] == '>') {
      if (base[i] <= base[i + 1]) base[i] = base[i + 1] + 1;
    }
  }

  ll ans = 0;

  for (auto &e : base) {
    ans += e;
  }

  printf("%lld\n", ans);

  return 0;
}
