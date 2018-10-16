#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e2 + 5);
const int MAX_M = (int)(3e2 + 5);

int n, m;
int a[MAX_N][MAX_M];

bool check(int x) {
  vector<queue<int>> qs(MAX_N);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      qs[i].push(a[i][j]);
    }
  }

  bool remain[MAX_M];

  for (int i = 1; i <= m; ++i) remain[i] = true;

  while (true) {
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; ++i) cnt[qs[i].front()] += 1;

    vector<int> ng;
    for (auto& e : cnt)
      if (e.second > x) ng.push_back(e.first);

    if (ng.empty()) return true;

    for (auto& e : ng) remain[e] = false;

    for (int i = 1; i <= n; ++i) {
      while (!qs[i].empty() && !remain[qs[i].front()]) qs[i].pop();
      if (qs[i].empty()) return false;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &(a[i][j]));
    }
  }

  int ok = MAX_M;
  int ng = 0;

  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  int ans = ok;

  printf("%d\n", ans);

  return 0;
}
