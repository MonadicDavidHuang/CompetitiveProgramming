#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

map<pair<int, int>, int> cnt;

pair<int, int> calc_key(int num) {
  string str = to_string(num);
  int head = (int)(str[0] - '0');
  int tail = (int)(str.back() - '0');

  return make_pair(head, tail);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    auto key = calc_key(i);

    cnt[key] += 1;
  }

  ll ans = 0LL;

  for (auto &e : cnt) {
    auto key = e.first;

    auto target = make_pair(key.second, key.first);

    ans += (ll)(cnt[key]) * (ll)(cnt[target]);
  }

  printf("%lld\n", ans);

  return 0;
}
