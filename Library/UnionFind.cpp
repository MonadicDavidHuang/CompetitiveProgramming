#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

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
  int n = 1000;

  UnionFind union_find(n);

  union_find.unite(1, 2);

  cout << (union_find.same(1, 2) ? "Yes" : "No") << endl;

  cout << union_find.size(1) << endl;

  cout << union_find.size(0) << endl;

  return 0;
}
