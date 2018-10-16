#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);

int h, w;
int a[MAX_N][MAX_N];

vector<tuple<int, int, int, int>> ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      scanf("%d", &(a[i][j]));
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j < w; ++j) {
      if (a[i][j] % 2 == 1) {
        a[i][j] -= 1;
        a[i][j + 1] += 1;
        ans.push_back(make_tuple(i, j, i, j + 1));
      }
    }
  }

  for (int i = 1; i < h; ++i) {
    if (a[i][w] % 2 == 1) {
      a[i][w] -= 1;
      a[i + 1][w] += 1;
      ans.push_back(make_tuple(i, w, i + 1, w));
    }
  }

  printf("%d\n", ans.size());

  for (auto &e : ans) {
    printf("%d %d %d %d\n", get<0>(e), get<1>(e), get<2>(e), get<3>(e));
  }

  return 0;
}
