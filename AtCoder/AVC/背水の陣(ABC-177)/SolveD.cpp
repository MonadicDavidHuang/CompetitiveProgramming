#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

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
int a[MAX_N], b[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  if (m == 0) {
    printf("1\n");
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a[i], &b[i]);
  }

  UnionFind uf(n + 1);

  for (int i = 0; i < m; ++i) {
    uf.unite(a[i], b[i]);
  }

  unordered_map<int, int> root2size;

  for (int i = 1; i <= n; ++i) {
    int root = uf.find(i);

    if (uf.size(root) == 1) {
      continue;
    }

    if (root2size.find(root) != root2size.end()) continue;
    root2size[root] = uf.size(root);
  }

  int ans = 0;

  while (true) {
    int cur_min = MAX_N;

    for (auto e : root2size) {
      if (e.second == 0) continue;
      cur_min = min(cur_min, e.second);
    }

    if (cur_min == MAX_N) break;

    ans += cur_min;

    for (auto e : root2size) {
      if (e.second == 0) continue;
      root2size[e.first] -= cur_min;
    }
  }

  printf("%d\n", ans);

  return 0;
}
