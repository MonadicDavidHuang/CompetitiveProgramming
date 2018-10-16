#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e3 + 5);
const int MAX_T = (int)(3e3 + 5);

int n, t;

int a[MAX_N];
int b[MAX_N];

int dp_l[MAX_N][MAX_T];
int dp_r[MAX_N][MAX_T];

int fix_i(int i) {
  int ret = -1;

  for (int j = 0; j <= (t - 1); ++j) {
    int tmp = dp_l[i - 1][j] + dp_r[i + 1][t - 1 - j];
    ret = max(ret, tmp);
  }

  ret += b[i];

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &t);

  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &(a[i]), &(b[i]));
  }

  for (int i = 1; i <= n; ++i) {
    for (int c = 1; c <= t; ++c) {
      if (c < a[i]) {
        dp_l[i][c] = dp_l[i - 1][c];
      } else {
        dp_l[i][c] = max(dp_l[i - 1][c], dp_l[i - 1][c - a[i]] + b[i]);
      }
    }
  }

  for (int i = n; i >= 1; --i) {
    for (int c = 1; c <= t; ++c) {
      if (c < a[i]) {
        dp_r[i][c] = dp_r[i + 1][c];
      } else {
        dp_r[i][c] = max(dp_r[i + 1][c], dp_r[i + 1][c - a[i]] + b[i]);
      }
    }
  }

  int ans = -1;

  for (int i = 1; i <= n; ++i) {
    ans = max(ans, fix_i(i));
  }

  printf("%d\n", ans);

  return 0;
}
