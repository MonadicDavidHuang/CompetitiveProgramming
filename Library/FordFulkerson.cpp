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

int main(void) {
  // Here your code !
  FordFulkerson ff;

  ff.add_edge(0, 1, 10);
  ff.add_edge(0, 2, 2);
  ff.add_edge(1, 2, 6);
  ff.add_edge(1, 3, 6);
  ff.add_edge(3, 2, 3);
  ff.add_edge(2, 4, 5);
  ff.add_edge(3, 4, 8);

  printf("%lld\n", ff.max_flow(0, 4));

  return 0;
}
