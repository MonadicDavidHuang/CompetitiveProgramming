#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k, l;

map<pair<int, int>, int> cnt;

/////////////////////////////////////////////////////////
class UnionFind {
 public:
  static const int MAX_N_LIB = (ll)(2e5 + 100);

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
  scanf("%d %d %d", &n, &k, &l);

  UnionFind union_find_k(n + 5);
  UnionFind union_find_l(n + 5);

  for (int i = 0; i < k; ++i) {
    int p, q;
    scanf("%d %d", &p, &q);
    union_find_k.unite(p, q);
  }

  for (int i = 0; i < l; ++i) {
    int r, s;
    scanf("%d %d", &r, &s);
    union_find_l.unite(r, s);
  }

  for (int i = 1; i <= n; ++i) {
    cnt[make_pair(union_find_k.find(i), union_find_l.find(i))] += 1;
  }

  for (int i = 1; i <= n; ++i) {
    int tmp = cnt[make_pair(union_find_k.find(i), union_find_l.find(i))];
    printf("%d ", tmp);
  }

  printf("\n");

  return 0;
}
