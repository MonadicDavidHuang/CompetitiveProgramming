#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, t;
vector<int> s;

pair<int, int> make_sorted_pair(int a, int b) {
  return make_pair(min(a, b), max(a, b));
}

int solve(vector<int> &s) {
  unordered_map<int, int> st;

  int ans = 0;

  vector<pair<int, int>> view;

  for (auto e : s) {
    if (st.empty()) {
      st[e] = 1;
    } else {
      if (st.find(t - e) != st.end()) {
        if (st[t - e] == 0) {
          st[e] += 1;
          continue;
        }
        ans += 1;
        st[t - e] -= 1;
        view.push_back(make_sorted_pair(e, t - e));
      } else {
        st[e] += 1;
      }
    }
  }

  sort(view.begin(), view.end());

  printf("-----------------\n");
  for (auto e : view) {
    printf("%d %d\n", e.first, e.second);
  }

  return ans;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &t);

  for (int i = 0; i < n; ++i) {
    int e;
    scanf("%d", &e);
    s.push_back(e);
  }

  int ans = solve(s);

  printf("-----------------\n");
  printf("%d\n", ans);

  return 0;
}
