#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int x[MAX_N], y[MAX_N];

vector<int> graph[MAX * 2 + 20];

int node2conn[MAX * 2 + 20];

void dfs(int node, int conn) {
  if (node2conn[node] >= 0) return;  // visited

  node2conn[node] = conn;

  for (auto &child : graph[node]) {
    dfs(child, conn);
  }
}

int main(void) {
  // Here your code !

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(x[i]), &(y[i]));

    int node_x = x[i];
    int node_y = y[i] + MAX;

    graph[node_x].push_back(node_y);
    graph[node_y].push_back(node_x);
  }

  for (int i = 0; i < MAX * 2 + 20; ++i) {
    node2conn[i] = -1;
  }

  for (int i = 0; i < n; ++i) {
    int node_x = x[i];
    dfs(node_x, i);
  }

  unordered_set<int> xs;
  for (int i = 0; i < n; ++i) {
    int node_x = x[i];
    xs.insert(node_x);
  }

  unordered_map<int, ll> conn2xnodenum;
  for (auto &e : xs) {
    conn2xnodenum[node2conn[e]] += 1LL;
  }

  unordered_set<int> ys;
  for (int i = 0; i < n; ++i) {
    int node_y = y[i] + MAX;
    ys.insert(node_y);
  }

  unordered_map<int, ll> conn2ynodenum;
  for (auto &e : ys) {
    conn2ynodenum[node2conn[e]] += 1LL;
  }

  unordered_set<int> conns;
  for (int i = 0; i < MAX * 2 + 20; ++i) {
    int conn = node2conn[i];
    if (conn < 0) continue;
    conns.insert(conn);
  }

  ll ans = 0LL;

  for (auto &key : conns) {
    ans += conn2xnodenum[key] * conn2ynodenum[key];
  }

  ans -= (ll)(n);

  printf("%lld\n", ans);

  return 0;
}
