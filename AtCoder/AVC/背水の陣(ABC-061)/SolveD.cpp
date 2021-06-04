#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e12 + 5);

const int MAX_N = (int)(1e3 + 5);
const int MAX_M = (int)(2e3 + 5);

struct edge {
  int from;
  int to;
  ll cost;
};

int n, m;
edge edges[MAX_M];

ll dist[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;
    scanf("%d %d %lld", &a, &b, &c);

    edges[i].from = a;
    edges[i].to = b;
    edges[i].cost = -c;
  }

  for (int i = 1; i <= n; ++i) {
    dist[i] = INF;
  }

  int goal_modify_cnt = 0;

  dist[1] = 0LL;

  for (int i = 0; i < 3 * n; ++i) {
    for (auto e : edges) {
      if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;

        if (e.to == n) goal_modify_cnt += 1;
      }
    }
  }

  if (goal_modify_cnt == 1) {
    printf("%lld\n", -dist[n]);
  } else {
    printf("inf\n");
  }

  return 0;
}
