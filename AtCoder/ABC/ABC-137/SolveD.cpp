#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;

priority_queue<pair<int, ll>> pq;

map<int, vector<ll>> cnt;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    int a;
    ll b;
    scanf("%d %lld", &a, &b);

    cnt[a].push_back(b);
  }

  // for (auto &e: cnt) {
  //   sort(e.second.begin(), e.second.end());
  // }

  // while (!pq.empty()) {
  //   auto cur = pq.top(); pq.pop();

  //   int remain = -1 * cur.first;
  //   int reward = cur.second;

  //   printf("%d %d\n", remain, reward);
  // }

  ans = 0LL;

  priority_queue<ll> pq;

  for (int i = 1; i <= m; ++i) {
    if (cnt.find(i) != cnt.end()) {
      for (auto &e : cnt[i]) {
        pq.push(e);
      }
    }

    if (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      ans += cur;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
