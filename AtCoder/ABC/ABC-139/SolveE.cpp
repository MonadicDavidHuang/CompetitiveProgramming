#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);
const int MAX_SIZE = (int)(MAX_N * MAX_N);

/////////////////////////////////////////////////////////////
// node in { 0, ... }
class TopologicalSort {
  using ts_graph = vector<vector<int>>;

 public:
  int n;
  ts_graph graph;
  vector<int> topological_sorted;
  vector<int> flg;  // 0: not-visited, 1: done, -1, temporary

  bool no_loop;

  TopologicalSort(ts_graph graph, int n) {
    this->flg = vector<int>(n, 0);
    this->graph = graph;
    this->n = n;
    init();
  }

  void init() { topological_sort(); }

  bool visit(int i) {
    if (flg[i] == -1) {
      return false;
    }

    if (flg[i] == 0) {
      flg[i] = -1;

      for (auto &e : graph[i]) {
        if (!visit(e)) {
          return false;
        }
      }

      flg[i] = 1;

      topological_sorted.push_back(i);

      return true;
    }

    return true;
  }

  void topological_sort() {
    for (int i = 0; i < n; ++i) {
      flg[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
      if (flg[i] == 0) {
        if (!visit(i)) {
          no_loop = false;
          return;
        }
      }
    }

    reverse(topological_sorted.begin(), topological_sorted.end());

    no_loop = true;
    return;
  }

  bool contains_loop() { return !no_loop; }

  vector<int> &get_sorted() { return topological_sorted; }
};
/////////////////////////////////////////////////////////////

int n;

int tmp[MAX_N];
vector<vector<int>> graph(MAX_SIZE);
unordered_map<int, int> memo;

int make_key(int a, int b) { return min(a, b) * n + max(a, b); }

int depth(int cur) {
  if (memo.find(cur) != memo.end()) return memo[cur];

  if (graph[cur].size() == 0) {
    return memo[cur] = 1;
  }

  int ret = -1;

  for (auto &e : graph[cur]) {
    ret = max(ret, depth(e));
  }

  ret += 1;

  return memo[cur] = ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n - 1; ++j) {
      scanf("%d", &(tmp[j]));
      tmp[j] -= 1;
    }

    int last = make_key(i, tmp[1]);

    for (int j = 2; j <= n - 1; ++j) {
      int cur = make_key(i, tmp[j]);
      graph[last].push_back(cur);
      last = cur;
    }
  }

  TopologicalSort ts(graph, MAX_SIZE);

  if (ts.contains_loop()) {
    printf("-1\n");
    return 0;
  }

  int ans = -1;

  for (int i = 0; i < MAX_SIZE; ++i) {
    ans = max(ans, depth(i));
  }

  printf("%d\n", ans);

  return 0;
}
