#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e2 + 5);
const int MAX_M = (int)(3e2 + 5);

int n, m;
int a[MAX_N][MAX_M];

bool remain[MAX_M];

pair<int, int> next_pop(vector<queue<int>>& qs) {
  vector<int> cnt(m + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cnt[qs[i].front()] += 1;
  }

  int max_sport = 1;
  int max_times = cnt[1];
  for (int i = 1; i <= m; ++i) {
    if (cnt[i] > max_times) {
      max_sport = i;
      max_times = cnt[i];
    }
  }

  return make_pair(max_sport, max_times);
}

void pop_one(vector<queue<int>>& qs) {
  for (int i = 1; i <= n; ++i) {
    while (!remain[qs[i].front()]) {
      qs[i].pop();
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

  for (int i = 1; i <= m; ++i) remain[i] = true;

  vector<queue<int>> qs(MAX_N);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      qs[i].push(a[i][j]);
    }
  }

  int ans = MAX_M;

  if (m == 1) {
    ans = next_pop(qs).second;
  } else {
    for (int i = 1; i < m; ++i) {
      auto tmp = next_pop(qs);
      int target = tmp.first;

      ans = min(ans, tmp.second);

      remain[target] = false;
      pop_one(qs);
    }
  }

  printf("%d\n", ans);

  return 0;
}
