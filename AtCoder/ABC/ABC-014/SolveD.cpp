#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
unordered_map<int, vector<int>> graph;
int q;

/////////////////////////////////////////////////////////////
class LowestCommonAncestor {
  using lca_graph = unordered_map<int, vector<int>>;

 public:
  static const int MAX_V = (int)(2e5 + 100);
  const int MAX_LOG_V = (int)(floor(log2(MAX_V)) + 10);

  vector<vector<int>> parent;
  vector<int> depth;

  lca_graph graph;
  int root;

  LowestCommonAncestor(lca_graph graph, int root, int v_num) {
    this->parent = vector<vector<int>>(MAX_LOG_V, vector<int>(v_num + 1, 0));
    this->depth = vector<int>(v_num + 1, 0);

    this->graph = graph;
    this->root = root;

    init(v_num);
  }

  void init(int v_num) {
    dfs(root, -1, 0);

    // initialize parent
    for (int k = 0; k + 1 < MAX_LOG_V; ++k) {
      for (int v = 1; v <= v_num; ++v) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }

  void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (int next_v : graph[v]) {
      if (next_v != p) dfs(next_v, v, d + 1);
    }
  }

  // return pair of (lca, path(u-lca) + path(v-lca))
  pair<int, int> calc_lca(int u, int v) {
    int path = 0;

    if (depth[u] > depth[v]) swap(u, v);

    // difference of depth can be represented as MAX_LOG_V-bit binary
    // apply parent[k][v] means "shorten depth of v pow(2, k)"
    // if k-th bit of difference is 1, difference of depth contains pow(2, k)
    // depth bit(1) appears on MAX_LOG_V-bit binary, are to turned to bit(0),
    // through this procedure from right side
    for (int k = 0; k < MAX_LOG_V; ++k) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
        path += (1 << k);
      }
    }

    if (u == v) return make_pair(u, path);

    // find lca by binary-search
    for (int k = MAX_LOG_V - 1; k >= 0; --k) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
        path += 2 * (1 << k);
      }
    }

    int lca = parent[0][u];
    path += 2;

    return make_pair(lca, path);
  }
};
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  LowestCommonAncestor lca(graph, 1, n);

  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    auto cur = lca.calc_lca(a, b);

    int tmp = cur.second + 1;
    printf("%d\n", tmp);
  }

  return 0;
}
