#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e13 + 5);

using ql = pair<ll, ll>;

const int MAX_N = (int)(3e2 + 5);

int n, m;
ll l;

ll cost[MAX_N][MAX_N];

int q;

ql jump[MAX_N][MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  scanf("%lld", &l);

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cost[i][j] = INF;
      cost[j][i] = INF;

      jump[i][j] = ql(INF, INF);
      jump[j][i] = ql(INF, INF);
    }
    cost[i][i] = 0L;
    jump[i][i] = ql(INF, INF);
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;

    scanf("%d %d %lld", &a, &b, &c);

    cost[a][b] = c;
    cost[b][a] = c;
  }

  for (int s = 1; s <= n; ++s) {
    priority_queue<pair<ql, int>, vector<pair<ql, int>>, greater<pair<ql, int>>>
        pq;

    pq.push(make_pair(ql(0L, 0L), s));

    jump[s][s] = ql(0L, 0L);

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();

      ll times = cur.first.first;
      ll running = cur.first.second;
      int node = cur.second;

      if (cur.first > jump[s][node]) continue;

      for (int i = 1; i <= n; ++i) {
        if (s == i) continue;
        if (cost[node][i] > l) continue;

        ll streched_running = running + cost[node][i];

        ll next_times = (streched_running > l) ? times + 1 : times;
        ll next_running =
            (streched_running > l) ? cost[node][i] : streched_running;

        auto candidate = ql(next_times, next_running);

        if (jump[s][i] <= candidate) continue;

        jump[s][i] = candidate;

        pq.push(make_pair(candidate, i));
      }
    }
  }

  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    int s, t;
    scanf("%d %d", &s, &t);

    ll ans = (jump[s][t].first == INF) ? -1L : jump[s][t].first;

    printf("%lld\n", ans);
  }

  return 0;
}
