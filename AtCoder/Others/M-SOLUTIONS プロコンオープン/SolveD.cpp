#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
vector<int> graph[MAX_N];

priority_queue<int> c_que;

int d[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n - 1; ++i) {
    int a, b;

    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d", &c);

    c_que.push(c);
  }

  int bias = c_que.top();

  queue<int> que;
  fill_n(d, n + 3, 0);

  que.push(1);

  int score = 0;

  while (!que.empty()) {
    int cur_node = que.front();
    que.pop();

    int cur_c = c_que.top();
    c_que.pop();

    d[cur_node] = cur_c;
    score += cur_c;

    for (auto e : graph[cur_node]) {
      if (d[e] > 0) continue;

      que.push(e);
    }
  }

  score -= bias;

  printf("%d\n", score);

  for (int i = 1; i <= n; ++i) {
    printf("%d ", d[i]);
  }

  printf("\n");

  return 0;
}
