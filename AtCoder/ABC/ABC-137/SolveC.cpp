#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

map<multiset<int>, int> cnt;

int n;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    multiset<int> key;

    for (auto &e : s) {
      key.insert(e);
    }

    cnt[key] += 1;
  }

  for (auto &e : cnt) {
    ll value = (ll)(e.second);

    ans += (value - 1) * (value) / 2LL;
  }

  printf("%lld\n", ans);

  return 0;
}
