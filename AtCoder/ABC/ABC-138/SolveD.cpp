#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n, q;
vector<int> graph[MAX_N];

ll lazy[MAX_N];
ll actual[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &q);

  for (int i = 1; i <= n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= q; ++i) {
    int p;
    ll x;
    scanf("%d %lld", &p, &x);

    lazy[p] += x;
  }

  queue<tuple<int, int, ll>> que;

  que.push(make_tuple(1, 0, 0LL));

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int node = get<0>(cur);
    int parent = get<1>(cur);
    ll acc = get<2>(cur);

    acc += lazy[node];

    actual[node] += acc;

    for (auto &e : graph[node]) {
      if (e == parent) continue;

      que.push(make_tuple(e, node, acc));
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%lld ", actual[i]);
  }
  printf("\n");

  return 0;
}
