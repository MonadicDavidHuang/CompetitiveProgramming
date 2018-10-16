#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e1 + 5);

int n, m;
bool graph[MAX_N][MAX_N];

int ans;

bool check(vector<int> cur) {
  for (int l = 0; l < cur.size(); ++l) {
    for (int s = l + 1; s < cur.size(); ++s) {
      if (!graph[cur[l]][cur[s]]) return false;
    }
  }
  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    graph[x][y] = true;
    graph[y][x] = true;
  }

  for (int i = 1; i <= n; ++i) {
    graph[i][i] = true;
  }

  ans = 0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> cur;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) cur.push_back(j + 1);
    }

    if (check(cur)) {
      ans = max(ans, (int)(cur.size()));
    }
  }

  printf("%d\n", ans);

  return 0;
}
