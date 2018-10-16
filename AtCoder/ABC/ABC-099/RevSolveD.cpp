#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);
const int MAX_C = (int)(3e1 + 5);

int n, c;
int diff[MAX_C][MAX_C];
int grid[MAX_N][MAX_N];

int cnt[3][MAX_C];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &c);

  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= c; ++j) {
      scanf("%d", &(diff[i][j]));
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &(grid[i][j]));
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cnt[(i + j) % 3][grid[i][j]] += 1;
    }
  }

  ans = INF;

  for (int i = c; i >= 1; --i) {
    for (int j = c; j >= 1; --j) {
      if (i == j) continue;
      for (int k = c; k >= 1; --k) {
        if (i == k || j == k) continue;

        ll tmp = 0LL;

        for (int col = 1; col <= c; ++col) {
          tmp += cnt[0][col] * diff[col][i];
          tmp += cnt[1][col] * diff[col][j];
          tmp += cnt[2][col] * diff[col][k];
        }

        ans = min(ans, tmp);
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
