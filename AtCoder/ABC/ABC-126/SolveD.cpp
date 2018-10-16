#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
vector<pair<int, ll>> graph[MAX_N];

int color[MAX_N];

void coloring(int first_color) {
  color[1] = first_color;

  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int cur_node = que.front();
    que.pop();

    for (auto next : graph[cur_node]) {
      int next_node = next.first;
      ll next_cost = next.second;

      if (color[next_node] >= 0) continue;

      color[next_node] =
          (next_cost % 2 == 0) ? color[cur_node] : (color[cur_node] + 1) % 2;

      que.push(next_node);
    }
  }
}

void reset() {
  for (int i = 0; i <= n; ++i) {
    color[i] = -1;
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    ll w;

    scanf("%d %d %lld", &from, &to, &w);

    graph[from].push_back(make_pair(to, w));
    graph[to].push_back(make_pair(from, w));
  }

  reset();

  coloring(1);

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", color[i]);
  }

  return 0;
}
