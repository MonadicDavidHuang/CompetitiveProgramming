#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e4 + 5);

int n;
int c[MAX_N];

ll dp[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(c[i]));
  }

  for (int i = 0; i <= n; ++i) {
    dp[i] = INF;
  }

  for (int i = 0; i < n; ++i) {
    *lower_bound(dp, dp + n, c[i]) = c[i];
  }

  int lis_length = lower_bound(dp, dp + n, INF) - dp;

  ans = n - lis_length;

  printf("%d\n", ans);

  return 0;
}
