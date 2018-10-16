#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);
const int MAX_M = (int)(2e5 + 5);
const int MAX_Q = (int)(1e5 + 5);

int n, m, q;

int cnt[MAX_N][MAX_N];
int memo[MAX_N][MAX_N];

int solve(int p, int q) {
  auto key = make_pair(p, q);
  if (memo[p][q] != -1) return memo[p][q];

  if (p > q) return 0;

  int ret = cnt[p][q];

  if (p == q) {
    return memo[p][q] = ret;
  }

  ret += solve(p + 1, q);
  ret += solve(p, q - 1);
  ret -= solve(p + 1, q - 1);

  return memo[p][q] = ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    cnt[l][r] += 1;
  }

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      memo[i][j] = -1;
    }

  for (int i = 0; i < q; ++i) {
    int p, q;
    scanf("%d %d", &p, &q);

    int ans = solve(p, q);

    printf("%d\n", ans);
  }

  return 0;
}
