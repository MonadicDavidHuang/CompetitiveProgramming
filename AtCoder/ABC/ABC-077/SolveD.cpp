#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int k;

bool visited[MAX_N];
ll dist[MAX_N];

ll ans;

ll solve() {
  fill_n(visited, k + 1, false);
  fill_n(dist, k + 1, INF);

  deque<pair<int, ll>> deq;

  deq.push_front(make_pair(1, 0LL));

  ll ret = 0;

  while (!deq.empty()) {
    auto cur = deq.front();
    deq.pop_front();

    int node = cur.first;
    ll cost = cur.second;

    if (visited[node]) continue;
    visited[node] = true;

    dist[node] = cost;

    if (node == 0) {
      ret = cost;
      break;
    }

    int next_p1 = (node + 1) % k;
    if (dist[next_p1] > cost + 1LL) {
      deq.push_back(make_pair(next_p1, cost + 1LL));
    }

    int next_t10 = (node * 10) % k;
    if (dist[next_t10] > cost) {
      deq.push_front(make_pair(next_t10, cost));
    }
  }

  return ret + 1LL;
}

int main(void) {
  // Here your code !
  scanf("%d", &k);

  ans = solve();

  printf("%lld\n", ans);

  return 0;
}
