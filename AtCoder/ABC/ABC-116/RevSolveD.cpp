#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;
vector<pair<ll, int>> vec_td;

unordered_map<int, int> ump;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    int t;
    ll d;
    scanf("%d %lld", &t, &d);
    vec_td.push_back(make_pair(d, t));
  }

  sort(vec_td.begin(), vec_td.end(), greater<pair<ll, int>>());

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  ll acc = 0LL;

  for (int i = 0; i < k; ++i) {
    auto cur = vec_td[i];

    acc += cur.first;
    ump[cur.second] += 1;
    if (ump[cur.second] > 1) pq.push(cur);
  }

  ans = acc + (ll)(ump.size()) * (ll)(ump.size());

  for (int i = k; i < n; ++i) {
    if (pq.empty()) break;

    auto cur = vec_td[i];
    if (ump.find(vec_td[i].second) != ump.end()) continue;

    auto last = pq.top();
    pq.pop();

    ump[last.second] -= 1;
    acc -= last.first;

    ump[cur.second] += 1;
    acc += cur.first;

    ans = max(ans, acc + (ll)(ump.size()) * (ll)(ump.size()));
  }

  printf("%lld\n", ans);

  return 0;
}
