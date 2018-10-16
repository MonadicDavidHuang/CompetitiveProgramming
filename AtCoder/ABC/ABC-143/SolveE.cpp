#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e13 + 5);

const int MAX_N = (int)(3e2 + 5);

int n, m;
ll l;

ll path[MAX_N][MAX_N];

ll jump[MAX_N][MAX_N];

int q;

void calc_shortest_paths() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (path[i][j] > path[i][k] + path[k][j]) {
          path[i][j] = path[i][k] + path[k][j];
        }
      }
    }
  }
}

void calc_shortest_jumps() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (jump[i][j] > jump[i][k] + jump[k][j]) {
          jump[i][j] = jump[i][k] + jump[k][j];
        }
      }
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d %lld", &n, &m, &l);

  // initialize
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      path[i][j] = INF;
      path[j][i] = INF;
    }
    path[i][i] = 0L;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;

    scanf("%d %d %lld", &a, &b, &c);

    path[a][b] = c;
    path[b][a] = c;
  }

  calc_shortest_paths();

  // prepare jump graph
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      jump[i][j] = INF;
      jump[j][i] = INF;

      if (path[i][j] <= l) {
        jump[i][j] = 1L;
        jump[j][i] = 1L;
      }
    }
    jump[i][i] = 0L;
  }

  calc_shortest_jumps();

  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    int s, t;
    scanf("%d %d", &s, &t);

    if (jump[s][t] == INF) {
      printf("%d\n", -1);
      continue;
    }

    ll ans = jump[s][t] - 1L;

    printf("%lld\n", ans);
  }

  return 0;
}
