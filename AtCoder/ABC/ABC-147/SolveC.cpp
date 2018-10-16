#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e1 + 5);

int n;
vector<vector<pair<int, int>>> data(MAX_N);

int tmp[MAX_N];

bool check() {
  for (int i = 0; i < n; ++i) {
    bool is_honest = tmp[i] == 1;

    if (!is_honest) continue;

    auto confess = data[i];

    for (auto &e : confess) {
      if (tmp[e.first] != e.second) {
        return false;
      }
    }
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < a; ++j) {
      int x, y;
      scanf("%d %d", &x, &y);
      data[i].push_back(make_pair(x - 1, y));
    }
  }

  int ans = 0;

  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      tmp[j] = (i >> j) & 1 ? 1 : 0;
    }

    if (!check()) continue;

    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      cnt += tmp[j];
    }

    ans = max(ans, cnt);
  }

  printf("%d\n", ans);

  return 0;
}
