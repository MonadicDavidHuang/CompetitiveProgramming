#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e9 + 7);
const int MAX_N = (int)(1e2 + 5);

int n;
int a, b;
int m;
vector<vector<int>> graph(MAX_N);

vector<int> path(MAX_N);
vector<vector<int>> dag(MAX_N);
map<int, ll> memo;

ll ans;

ll calc(int node) {
  if (memo.find(node) != memo.end()) return memo[node];

  if (node == b) return memo[node] = 1LL;

  ll cnt = 0LL;

  for (auto next_node : dag[node]) {
    cnt += calc(next_node);
    cnt %= MOD;
  }

  return memo[node] = cnt;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);
  scanf("%d %d", &a, &b);
  scanf("%d", &m);

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  queue<pair<int, int>> que;
  set<int> visited;

  que.push(make_pair(a, 0));
  visited.insert(a);

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int node = cur.first;
    int acc_path = cur.second;

    path[node] = acc_path;

    for (auto next_node : graph[node]) {
      if (visited.find(next_node) != visited.end()) continue;

      que.push(make_pair(next_node, acc_path + 1));
      visited.insert(next_node);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (graph[i].empty()) continue;
    for (auto node : graph[i]) {
      if (path[i] == path[node] + 1) {
        dag[node].push_back(i);
      }
    }
  }

  ans = calc(a);

  printf("%lld\n", ans);

  return 0;
}
