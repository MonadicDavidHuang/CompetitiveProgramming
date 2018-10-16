#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int n, m;
vector<vector<int>> graph(MAX_N);

int ans = 0;

void dfs(int node, set<int> visited) {
  if (visited.size() == n) {
    ans += 1;
    return;
  }

  for (auto next : graph[node]) {
    if (visited.find(next) == visited.end()) {
      set<int> new_visited = visited;
      new_visited.insert(next);
      dfs(next, new_visited);
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  set<int> visited;
  visited.insert(1);

  dfs(1, visited);

  printf("%d\n", ans);

  return 0;
}
