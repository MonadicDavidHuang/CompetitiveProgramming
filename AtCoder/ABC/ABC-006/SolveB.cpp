#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MOD = (ll)(1e4 + 7);

const int MAX_N = (int)(1e6 + 5);

int n;
int dp[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  dp[1] = 0;
  dp[2] = 0;
  dp[3] = 1;

  for (int i = 4; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    dp[i] %= MOD;
  }

  printf("%d\n", dp[n]);

  return 0;
}
