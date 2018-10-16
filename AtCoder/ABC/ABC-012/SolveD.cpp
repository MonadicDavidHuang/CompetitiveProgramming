#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e2 + 5);
const int MAX_M = (int)(5e4 + 5);

int n, m;
int a[MAX_M], b[MAX_M], t[MAX_M];

ll path[MAX_N][MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &(a[i]), &(b[i]), &(t[i]));
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        path[i][j] = 0LL;
      else
        path[i][j] = INF;
    }
  }

  for (int i = 0; i < m; ++i) {
    path[a[i]][b[i]] = t[i];
    path[b[i]][a[i]] = t[i];
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
      }
    }
  }

  ans = INF;

  for (int i = 1; i <= n; ++i) {
    ll cur = -1LL;
    for (int j = 1; j <= n; ++j) {
      if (path[i][j] == INF) continue;

      cur = max(cur, path[i][j]);
    }
    ans = min(ans, cur);
  }

  printf("%lld\n", ans);

  return 0;
}
