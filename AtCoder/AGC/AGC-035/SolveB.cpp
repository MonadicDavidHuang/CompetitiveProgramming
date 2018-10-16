#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////
class UnionFind {
 public:
  static const int MAX_N_LIB = (int)(2e5 + 100);

  int uf_par[MAX_N_LIB];
  int uf_rank[MAX_N_LIB];
  int uf_size[MAX_N_LIB];

  UnionFind(int n) { init(n); }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      uf_par[i] = i;
      uf_rank[i] = 0;
      uf_size[i] = 1;
    }
  }

  int find(int x) {
    if (uf_par[x] == x)
      return x;
    else {
      return uf_par[x] = find(uf_par[x]);
    }
  }

  void unite(int leaf_x, int leaf_y) {
    int x = find(leaf_x);
    int y = find(leaf_y);

    if (x == y) return;

    if (uf_rank[x] < uf_rank[y]) {
      uf_par[x] = y;
      uf_size[y] += uf_size[x];
    } else if (uf_rank[x] > uf_rank[y]) {
      uf_par[y] = x;
      uf_size[x] += uf_size[y];
    } else {
      uf_par[y] = x;
      uf_size[x] += uf_size[y];
      uf_rank[x] += 1;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return uf_size[find(x)]; }
};
/////////////////////////////////////////////////////////

const int MAX_N = (int)(1e5 + 5);

int n, m;
vector<pair<int, int>> edge;

int out[MAX_N];
vector<int> graph[MAX_N];

UnionFind uf(MAX_N);

vector<pair<int, int>> ans;

void routine(int cur, int parent) {
  if (out[cur] % 2 == 1) {
    ans.push_back(make_pair(cur, parent));
    out[cur] += 1;
  } else {
    ans.push_back(make_pair(parent, cur));
    out[parent] += 1;
  }
  return;
}

void dfs(int cur, int parent) {
  if (graph[cur].size() > 1) {
    for (auto &e : graph[cur]) {
      if (e == parent) continue;
      dfs(e, cur);
    }
  }

  routine(cur, parent);
  return;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    edge.push_back(make_pair(a, b));
  }

  if (m % 2 == 1) {
    printf("%d\n", -1);
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    out[i] = 0;
  }

  for (auto &e : edge) {
    if (uf.same(e.first, e.second)) {
      ans.push_back(e);
      out[e.first] += 1;
    } else {
      graph[e.first].push_back(e.second);
      graph[e.second].push_back(e.first);
      uf.unite(e.first, e.second);
    }
  }

  for (auto &e : graph[1]) {
    dfs(e, 1);
  }

  for (auto &e : ans) {
    printf("%d %d\n", e.first, e.second);
  }

  return 0;
}
