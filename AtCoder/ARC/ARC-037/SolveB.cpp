#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);
const int MAX_M = (int)(MAX_N * (MAX_N - 1) / 2 + 5);

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

int n, m;
int u[MAX_M];
int v[MAX_M];

unordered_map<int, int> cnt;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &(u[i]), &(v[i]));
  }

  UnionFind uf(n + 3);

  for (int i = 1; i <= n; ++i) {
    uf.unite(i, i);
  }

  for (int i = 0; i < m; ++i) {
    uf.unite(u[i], v[i]);
  }

  for (int i = 0; i < m; ++i) {
    cnt[uf.find(u[i])] += 1;
  }

  int ans = 0;

  for (auto &e : cnt) {
    if (e.second == (uf.size(e.first) - 1)) ans += 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (uf.size(i) == 1) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
