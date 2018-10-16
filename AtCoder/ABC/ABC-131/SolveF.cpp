#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int x[MAX_N], y[MAX_N];

/////////////////////////////////////////////////////////
// node in { 0, ... }
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

int main(void) {
  // Here your code !

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(x[i]), &(y[i]));
  }

  UnionFind uf(MAX_N * 2 + 20);

  for (int i = 0; i < n; ++i) {
    int node_x = x[i];
    int node_y = y[i] + MAX;

    uf.unite(node_x, node_y);
  }

  unordered_map<int, int> conn2edgenum;

  for (int i = 0; i < n; ++i) {
    int node_x = x[i];
    conn2edgenum[uf.find(node_x)] += 1;
  }

  unordered_set<int> xs;
  for (int i = 0; i < n; ++i) {
    int node_x = x[i];
    xs.insert(node_x);
  }

  unordered_map<int, ll> conn2xnodenum;
  for (auto &e : xs) {
    conn2xnodenum[uf.find(e)] += 1LL;
  }

  unordered_set<int> ys;
  for (int i = 0; i < n; ++i) {
    int node_y = y[i] + MAX;
    ys.insert(node_y);
  }

  unordered_map<int, ll> conn2ynodenum;
  for (auto &e : ys) {
    conn2ynodenum[uf.find(e)] += 1LL;
  }

  ll ans = 0LL;

  for (auto &e : conn2edgenum) {
    int key = e.first;

    ans += conn2xnodenum[key] * conn2ynodenum[key] - (ll)(conn2edgenum[key]);
  }

  printf("%lld\n", ans);

  return 0;
}
