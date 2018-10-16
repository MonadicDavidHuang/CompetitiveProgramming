#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
class FordFulkerson {
 public:
  static const ll INF = (ll)(1e10 + 5);
  static const int MAX_N = (int)(1e2 + 100);

  struct edge {
    int to, rev;
    ll cap;
  };

  vector<edge> graph[MAX_N];
  bool used[MAX_N];

  FordFulkerson() {}

  void init() {}

  void add_edge(int from, int to, ll cap) {
    graph[from].push_back((edge){to, (int)(graph[to].size()), cap});
    graph[to].push_back((edge){from, (int)(graph[from].size() - 1), 0LL});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t) return f;

    used[v] = true;

    for (int i = 0; i < graph[v].size(); ++i) {
      edge &e = graph[v][i];

      if (!used[e.to] && e.cap > 0) {
        ll d = dfs(e.to, t, min(f, e.cap));

        if (d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }

    return 0LL;
  }

  ll max_flow(int s, int t) {
    ll flow = 0LL;

    for (;;) {
      memset(used, 0, sizeof(used));

      ll f = dfs(s, t, INF);

      if (f == 0) return flow;

      flow += f;
    }
  }
};
/////////////////////////////////////////////////////////////

const int MAX_N = (int)(1e2 + 5);

int n, g, e;
int p[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &g, &e);

  for (int i = 1; i <= g; ++i) {
    scanf("%d", &(p[i]));
  }

  FordFulkerson ff;

  for (int i = 0; i < e; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ff.add_edge(a, b, 1LL);
    ff.add_edge(b, a, 1LL);
  }

  for (int i = 1; i <= g; ++i) {
    ff.add_edge(p[i], n + 1, 1LL);
    ff.add_edge(n + 1, p[i], 1LL);
  }

  printf("%lld\n", ff.max_flow(0, n + 1));

  return 0;
}
