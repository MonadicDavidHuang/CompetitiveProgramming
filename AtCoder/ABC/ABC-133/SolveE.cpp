#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
ll k;

vector<int> graph[MAX_N];

ll ans;

ll dfs(int cur, int parent, bool root_parent) {
  ll remain = root_parent ? k - 1 : k - 2;

  int num_child = graph[cur].size();
  if (!root_parent) num_child -= 1;

  if (num_child > remain) {
    return 0;
  }

  ll ret = 1LL;

  for (int i = 0; i < num_child; ++i) {
    ret *= remain;
    ret %= MOD;
    remain -= 1LL;
  }

  for (auto e : graph[cur]) {
    if (e == parent) continue;

    ret *= dfs(e, cur, false);
    ret %= MOD;
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  ans = k * dfs(1, 0, true);
  ans %= MOD;

  printf("%lld\n", ans);

  return 0;
}
