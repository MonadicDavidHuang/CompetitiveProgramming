#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e5 + 5);

/////////////////////////////////////////////////////////////
class ZAlgorithm {
 public:
  string s;
  string t;
  string phi;
  string sct;
  vector<int> z;

  ZAlgorithm(string s, string t, char phi) {
    this->z = vector<int>(t.size() + 1 + s.size(), 0);

    this->s = s;
    this->t = t;
    this->phi = phi;
    init();
  }

  void init() {
    sct = t + phi + s;
    make_z();
  }

  void make_z() {
    int n = sct.size();
    int l = 0, r = 0;

    z[0] = sct.size();

    for (int i = 1; i < n; ++i) {
      if (i > r) {
        l = r = i;
        while (r < n && sct[r - l] == sct[r]) r += 1;

        z[i] = r - l;
        r -= 1;
      } else {
        int k = i - l;  // focus at prefix-substring (begin with sct[k]) with
                        // which already dealed

        // no prefix-substring (begin with sct[i]) longer than (r - i + 1) could
        // be expected since, "sct[0..(r - l)] == sct[l..r]" entails "sct[k..(r
        // - l)] == sct[i..r]", but z[k] is smaller than length of sct[i..r]
        if (z[k] < r - i + 1) {
          z[i] = z[k];
        } else {  // there could be longer prefix-substring (begin with sct[i])
          l = i;
          while (r < n && sct[r - l] == sct[r]) r += 1;

          z[i] = r - l;
          r -= 1;
        }
      }
    }
  }

  bool match_from(int i) { return z[t.size() + 1 + i] == t.size(); }

  int z_value(int i) { return z[t.size() + 1 + i]; }
};
/////////////////////////////////////////////////////////////

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

string s;
string t;

vector<vector<int>> graph(MAX_N);

int path[MAX_N];

int ans;

int main(void) {
  // Here your code !
  cin >> s;
  cin >> t;

  int target_size = s.size() + t.size();

  string s_replicate = s;

  while (s_replicate.size() < target_size) {
    s_replicate += s;
  }

  ZAlgorithm za(s_replicate, t, '_');

  for (int i = 0; i < s.size(); ++i) {
    if (za.match_from(i)) {
      int target = (i + t.size()) % s.size();

      graph[i].push_back(target);
    }
  }

  TopologicalSort ts(graph, s.size());

  if (ts.contains_loop()) {
    printf("%d\n", -1);
    return 0;
  }

  int length = 0;

  for (auto &e : ts.get_sorted()) {
    for (auto &child : graph[e]) {
      path[child] = max(path[child], path[e] + (int)(t.size()));
      length = max(length, path[child]);
    }
  }

  ans = length / t.size();

  printf("%d\n", ans);

  return 0;
}
