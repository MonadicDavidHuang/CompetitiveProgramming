#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n, k;

double memo[MAX_N][MAX_N];

double ans;

double prob(int step, int remain) {
  if (remain <= 0) return 0.0;

  if ((n - step + 1) <= remain) return 1.0;

  if (memo[step][remain] >= 0) return memo[step][remain];

  double is_n = 1.0 / (double)(n - step + 1);

  double is_max = 1.0 / (double)(step);

  double is_fake_max = (1.0 - is_n) * is_max;

  double is_not_max = (1.0 - is_n) * (1.0 - is_max);

  double ret = 0.0;

  ret += is_not_max * prob(step + 1, remain);

  double take = is_n + is_fake_max * prob(step + 1, remain - 1);

  double leave = is_fake_max * prob(step + 1, remain);

  ret += max(take, leave);

  return memo[step][remain] = ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      memo[i][j] = -1;
    }
  }

  ans = prob(1, k);

  printf("%lf\n", ans);

  return 0;
}
