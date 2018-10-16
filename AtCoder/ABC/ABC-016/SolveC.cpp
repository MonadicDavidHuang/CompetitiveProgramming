#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int n, m;

set<int> graph[MAX_N];

set<int> f_of_f[MAX_N];

int ans[MAX_N];

void calc() {
  for (int i = 1; i <= n; ++i) {
    for (auto f : graph[i]) {
      for (auto ff : graph[f]) {
        if (ff == i) continue;
        f_of_f[i].insert(ff);
      }
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].insert(b);
    graph[b].insert(a);
  }

  calc();

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (f_of_f[i].find(j) != f_of_f[i].end() &&
          f_of_f[j].find(i) != f_of_f[j].end() &&
          graph[i].find(j) == graph[i].end()) {
        ans[i] += 1;
        ans[j] += 1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
