#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

vector<vector<int>> graph(MAX_N);

int oa[MAX_N], ob[MAX_N];

bool visited[MAX_N];

int max_color = 0;

map<pair<int, int>, int> ans;

void coloring(int node) {
  if (visited[node]) return;

  visited[node] = true;

  set<int> used;

  vector<int> nexts;

  for (int i = 0; i < graph[node].size(); ++i) {
    int to = graph[node][i];
    auto node_to_to = make_pair(node, to);
    auto to_to_node = make_pair(to, node);

    if (ans.find(node_to_to) == ans.end() &&
        ans.find(to_to_node) == ans.end()) {
      nexts.push_back(to);
      continue;
    }

    if (ans.find(node_to_to) != ans.end()) {
      used.insert(ans[node_to_to]);
      continue;
    }

    if (ans.find(to_to_node) != ans.end()) {
      used.insert(ans[to_to_node]);
    }
  }

  int new_node_num = nexts.size();

  int remaining = max_color - (int)(used.size());

  if (remaining < new_node_num) {
    max_color += (new_node_num - remaining);
  }

  int idx = 1;

  for (auto &to : nexts) {
    auto node_to_to = make_pair(node, to);
    auto to_to_node = make_pair(to, node);

    while (used.find(idx) != used.end()) idx += 1;

    ans[node_to_to] = idx;
    ans[to_to_node] = idx;

    used.insert(idx);
  }

  for (auto &to : nexts) {
    coloring(to);
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    oa[i] = a;
    ob[i] = b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    visited[i] = false;
  }

  coloring(1);

  printf("%d\n", max_color);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d\n", ans[make_pair(oa[i], ob[i])]);
  }

  return 0;
}
