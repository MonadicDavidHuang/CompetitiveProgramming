#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(3e2 + 5);
const int MAX_W = (int)(3e2 + 5);
const int MAX_NUM = (int)(MAX_H * MAX_W);

int h, w, d;
int a[MAX_H][MAX_W];
int q;

map<int, pair<int, int>> to_index;
int cost[MAX_NUM];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &h, &w, &d);

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      scanf("%d", &(a[i][j]));
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      to_index[a[i][j]] = make_pair(i, j);
    }
  }

  for (int i = 1; i <= h * w; ++i) {
    if (cost[i] > 0) continue;

    for (int j = i + d; j <= h * w; j += d) {
      auto last = to_index[j - d];
      auto cur = to_index[j];

      cost[j] += abs(cur.first - last.first) + abs(cur.second - last.second);
      cost[j] += cost[j - d];
    }
  }

  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);

    printf("%d\n", cost[r] - cost[l]);
  }

  return 0;
}
