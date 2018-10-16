#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int n, m;

map<int, set<int>> mp;

int p[MAX_N];

int ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int s;
      scanf("%d", &s);

      mp[i].insert(s);
    }
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d", &(p[i]));
  }

  for (int i = 0; i < 1 << n; ++i) {
    map<int, int> switch_cnt;

    for (int j = 0; j < m; ++j) {
      switch_cnt[j] = 0;
    }

    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        for (auto e : mp) {
          if (e.second.find(j + 1) != e.second.end()) {
            switch_cnt[e.first] += 1;
          }
        }
      }
    }

    int cur_cnt = 0;
    for (auto e : switch_cnt) {
      if (e.second % 2 == p[e.first]) cur_cnt += 1;
    }

    ans += (cur_cnt == m) ? 1 : 0;
  }

  printf("%d\n", ans);

  return 0;
}
