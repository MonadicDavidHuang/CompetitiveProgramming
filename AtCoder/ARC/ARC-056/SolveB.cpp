#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n, m, s;
vector<vector<int>> graph(MAX_N);

bool visited[MAX_N];
int max_min_node_of_path[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &m, &s);

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    visited[i] = false;
    max_min_node_of_path[i] = -1;
  }

  priority_queue<pair<int, int>> pq;

  pq.push(make_pair(s, s));

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    int max_min_node = cur.first;
    int node = cur.second;

    if (visited[node]) continue;

    max_min_node_of_path[node] = max(max_min_node_of_path[node], max_min_node);

    visited[node] = true;

    for (auto &e : graph[node]) {
      int next_max_min_node = min(max_min_node, e);

      if (next_max_min_node <= max_min_node_of_path[e]) continue;

      pq.push(make_pair(next_max_min_node, e));
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (max_min_node_of_path[i] >= i) printf("%d\n", i);
  }

  return 0;
}
