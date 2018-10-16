#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const int INF = (int)(3e5 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int ng1, ng2, ng3;

int dp[MAX_N];

int main(void) {
  // Here your code !

  scanf("%d", &n);
  scanf("%d", &ng1);
  scanf("%d", &ng2);
  scanf("%d", &ng3);

  if (n == ng1 || n == ng2 || n == ng3) {
    printf("NO\n");

    return 0;
  }

  for (int i = 0; i <= n; ++i) {
    dp[i] = INF;
  }
  dp[n] = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (i == ng1 || i == ng2 || i == ng3) {
      continue;
    }

    for (int d = 1; d <= 3; ++d) {
      if (i + d <= n) {
        dp[i] = min(dp[i], dp[i + d] + 1);
      }
    }
  }

  if (dp[0] <= 100) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
