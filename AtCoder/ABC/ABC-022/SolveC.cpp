#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e2 + 5);

int n, m;

ll cost[MAX_N][MAX_N];

ll path[MAX_N][MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cost[i][j] = INF;
  for (int i = 1; i <= n; ++i) cost[i][i] = 0;

  for (int i = 0; i < m; ++i) {
    int u, v;
    ll l;
    scanf("%d %d %lld", &u, &v, &l);
    cost[u][v] = l;
    cost[v][u] = l;
  }

  vector<int> cand;

  for (int i = 2; i <= n; ++i) {
    if (cost[1][i] < INF) {
      cand.push_back(i);
    }
  }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      path[i][j] = cost[i][j];
    }

  for (auto e : cand) {
    path[1][e] = INF;
    path[e][1] = INF;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     printf("%d %d: %lld\n", i, j, cost[i][j]);
  //   }
  // }

  ans = INF;

  for (int i = 0; i < cand.size(); ++i) {
    for (int j = 0; j < cand.size(); ++j) {
      if (i == j) continue;
      ll tmp = cost[1][cand[i]] + cost[cand[j]][1] + path[cand[i]][cand[j]];
      ans = min(ans, tmp);
    }
  }

  if (ans < INF) {
    printf("%lld\n", ans);
  } else {
    printf("-1\n");
  }

  return 0;
}
