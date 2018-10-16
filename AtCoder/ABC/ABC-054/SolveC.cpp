#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int n, m;

vector<set<int>> graph(MAX_N);

vector<int> order;

int ans;

bool check() {
  for (int i = 0; i < n - 1; ++i) {
    int src = order[i];
    int tar = order[i + 1];
    if (graph[src].find(tar) == graph[src].end()) return false;
  }
  return true;
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

  for (int i = 1; i <= n; ++i) {
    order.push_back(i);
  }

  check();

  do {
    if (check()) ans += 1;
  } while (next_permutation(order.begin() + 1, order.end()));

  printf("%d\n", ans);

  return 0;
}
