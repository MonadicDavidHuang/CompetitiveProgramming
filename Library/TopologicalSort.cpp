#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

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

int main(void) {
  // Here your code !
  int n = 10;

  vector<vector<int>> graph(n);

  graph[0].push_back(1);
  graph[2].push_back(0);

  TopologicalSort ts(graph, 3);

  if (!ts.contains_loop()) {
    printf("no loop\n");
  }

  for (auto &e : ts.get_sorted()) {
    printf("%d ", e);
  }
  printf("\n");

  return 0;
}
