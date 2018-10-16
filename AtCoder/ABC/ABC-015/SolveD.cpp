#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_W = (int)(1e5 + 5);
const int MAX_N = (int)(5e1 + 5);

int w;
int n, k;
int a[MAX_N], b[MAX_N];

int dp[MAX_N][MAX_W][MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &w);

  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(a[i]), &(b[i]));
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      for (int l = 0; l <= n; ++l) {
        dp[i][j][l] = -1;
      }
    }
  }

  for (int j = 0; j <= w; ++j) {
    for (int l = 0; l <= n; ++l) {
      dp[0][j][l] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= w; ++j) {
      for (int l = 0; l <= n; ++l) {
        if (j + a[i] <= w) {
          dp[i + 1][j + a[i]][l + 1] =
              max(dp[i + 1][j + a[i]][l + 1], dp[i][j][l] + b[i]);
        }
        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
      }
    }
  }

  ans = -1;

  for (int j = 0; j <= w; ++j) {
    for (int l = 0; l <= k; ++l) {
      ans = max(ans, dp[n][j][l]);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
