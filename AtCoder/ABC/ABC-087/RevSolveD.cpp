#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, m;
vector<vector<pair<int, ll>>> graph(MAX_N);

ll pos[MAX_N];
bool visited[MAX_N];

bool check(int node, ll suppose) {
  if (visited[node]) {
    return pos[node] == suppose;
  }

  pos[node] = suppose;
  visited[node] = true;

  for (auto &e : graph[node]) {
    if (!check(e.first, pos[node] + e.second)) {
      return false;
    }
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int l, r;
    ll d;
    scanf("%d %d %lld", &l, &r, &d);
    graph[l].push_back(make_pair(r, d));
    graph[r].push_back(make_pair(l, -d));
  }

  for (int i = 1; i <= n; ++i) {
    visited[i] = false;
  }

  for (int i = 1; i <= n; ++i) {
    if (visited[i] || graph[i].empty()) continue;
    if (!check(i, 0LL)) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
