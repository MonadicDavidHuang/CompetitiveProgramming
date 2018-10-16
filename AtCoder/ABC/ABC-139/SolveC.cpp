#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll h[MAX_N];

int memo[MAX_N];

int solve(int index) {
  if (memo[index] != -1) {
    return memo[index];
  }

  if (index == n - 1) {
    return memo[index] = 0;
  }

  if (h[index] >= h[index + 1]) {
    return memo[index] = solve(index + 1) + 1;
  }

  return memo[index] = 0;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(h[i]));
  }

  for (int i = 0; i < n; ++i) {
    memo[i] = -1;
  }

  int ans = -1;

  for (int i = 0; i < n; ++i) {
    ans = max(ans, solve(i));
  }

  printf("%d\n", ans);

  return 0;
}
