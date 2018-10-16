#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e2 + 5);

int n;

vector<vector<int>> graph(MAX_N);

vector<int> paint(MAX_N);

ll path[MAX_N][MAX_N];

// color: -1, 0, 1
bool coloring(int node, int color) {
  if (paint[node] == 0) {  // not painted
    paint[node] = color;
    for (auto &next : graph[node]) {
      if (!coloring(next, color * -1)) {
        return false;
      }
    }
  } else {  // already painted
    return paint[node] == color;
  }

  return true;
}

bool check() {
  // initialize
  for (int i = 1; i <= n; ++i) paint[i] = 0;  // no coloar at first

  return coloring(1, 1);
}

ll calc() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (path[i][j] > path[i][k] + path[k][j]) {
          path[i][j] = path[i][k] + path[k][j];
        }
      }
    }
  }

  ll ret = -1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (path[i][j] == INF) continue;
      ret = max(ret, path[i][j]);
    }
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  // prepare graph
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      path[i][j] = INF;
    }
  }

  for (int i = 1; i <= n; ++i) {
    path[i][i] = 0LL;
  }

  // make graph
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;

    for (int j = 0; j < n; ++j) {
      if (tmp[j] == '0') continue;
      graph[i + 1].push_back(j + 1);
      path[i + 1][j + 1] = 1LL;
    }
  }

  if (!check()) {
    printf("%d\n", -1);
    return 0;
  }

  ll ans = calc() + 1LL;

  printf("%lld\n", ans);

  return 0;
}
