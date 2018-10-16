#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e3 + 5);
const int MAX_M = (int)(5e3 + 5);

int n, m;
ll p;

vector<tuple<int, int, ll>> edges;

vector<int> graph[MAX_N];
vector<int> graph_rev[MAX_N];

bool rfb[MAX_N];  // reachable from begin
bool rte[MAX_N];  // reachable to end

ll d[MAX_N];

void dfs_from(int node) {
  if (rfb[node]) return;

  rfb[node] = true;

  for (auto &e : graph[node]) {
    dfs_from(e);
  }
}

void dfs_to(int node) {
  if (rte[node]) return;

  rte[node] = true;

  for (auto &e : graph_rev[node]) {
    dfs_to(e);
  }
}

void check_reachability() {
  for (int i = 0; i < n; ++i) {
    rfb[i] = false;
    rte[i] = false;
  }

  dfs_from(0);
  dfs_to(n - 1);
}

bool ok(int node) { return (rfb[node] && rte[node]); }

bool check_negative_loop() {
  ll td[MAX_N];

  fill(td, td + n + 3, 0);

  for (int i = 0; i < n; ++i) {
    for (auto &e : edges) {
      if (!ok(get<0>(e)) || !ok(get<1>(e))) continue;

      if (td[get<1>(e)] > td[get<0>(e)] + get<2>(e)) {
        td[get<1>(e)] = td[get<0>(e)] + get<2>(e);

        if (i == n - 1) return true;
      }
    }
  }

  return false;
}

void bellman_ford() {
  for (int i = 0; i < n; ++i) d[i] = INF;

  d[0] = 0;

  while (true) {
    bool update = false;

    for (auto &e : edges) {
      if (!ok(get<0>(e)) || !ok(get<1>(e))) continue;

      if (d[get<1>(e)] > d[get<0>(e)] + get<2>(e)) {
        d[get<1>(e)] = d[get<0>(e)] + get<2>(e);

        update = true;
      }
    }

    if (!update) break;
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d %lld", &n, &m, &p);

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;
    scanf("%d %d %lld", &a, &b, &c);

    // 1-index to 0-index
    a -= 1;
    b -= 1;

    // maximize plus => minimize minus
    edges.emplace_back(a, b, -1LL * (c - p));

    graph[a].push_back(b);
    graph_rev[b].push_back(a);
  }

  check_reachability();

  if (check_negative_loop()) {
    printf("%d\n", -1);
    return 0;
  }

  bellman_ford();

  ll ans = -1LL * min(d[n - 1], 0LL);

  printf("%lld\n", ans);

  return 0;
}
