#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using node = pair<int, int>;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;
map<node, vector<node>> graph;
int s, t;

map<node, int> path_map;

int ans;

int calc() {
  queue<node> que;
  set<node> visited;

  que.push(node(s, 0));
  path_map[node(s, 0)] = 0;
  visited.insert(node(s, 0));

  while (!que.empty()) {
    node cur_node = que.front();
    que.pop();

    int cur_path = path_map[cur_node];

    for (node &next_node : graph[cur_node]) {
      if (visited.find(next_node) != visited.end()) continue;

      que.push(next_node);
      path_map[next_node] = cur_path + 1;
      visited.insert(next_node);
    }
  }

  return (path_map.find(node(t, 0)) == path_map.end())
             ? -1
             : path_map[node(t, 0)] / 3;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[node(u, 0)].push_back(node(v, 1));
    graph[node(u, 1)].push_back(node(v, 2));
    graph[node(u, 2)].push_back(node(v, 0));
  }

  scanf("%d %d", &s, &t);

  ans = calc();

  printf("%d\n", ans);

  return 0;
}
