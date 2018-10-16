#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;

int co_graph[MAX_N];

vector<pair<int, int>> ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; ++i) {
      co_graph[i] = n - (i - 1);
      co_graph[n - (i - 1)] = i;
    }

  } else {
    for (int i = 1; i <= (n - 1) / 2; ++i) {
      co_graph[i] = n - i;
      co_graph[n - i] = i;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (i == j) continue;
      if (co_graph[i] == j) continue;

      ans.push_back(make_pair(i, j));
    }
  }

  printf("%d\n", ans.size());

  for (auto &e : ans) {
    printf("%d %d\n", e.first, e.second);
  }

  return 0;
}
