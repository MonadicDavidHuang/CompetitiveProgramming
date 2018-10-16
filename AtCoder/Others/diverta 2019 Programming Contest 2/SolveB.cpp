#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n;
ll x[MAX_N], y[MAX_N];

map<pair<ll, ll>, int> cnt;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  if (n == 1) {
    printf("%d\n", 1);

    return 0;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(x[i]), &(y[i]));
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll diff_x = x[i] - x[j];
      ll diff_y = y[i] - y[j];

      cnt[make_pair(diff_x, diff_y)] += 1;
      cnt[make_pair(-1LL * diff_x, -1LL * diff_y)] += 1;
    }
  }

  int tmp_max = -1;

  for (auto &e : cnt) {
    tmp_max = max(tmp_max, e.second);
  }

  printf("%d\n", n - 1 - tmp_max + 1);

  return 0;
}
