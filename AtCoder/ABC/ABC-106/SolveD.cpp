#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);
const int MAX_M = (int)(2e5 + 5);
const int MAX_Q = (int)(1e5 + 5);

int n, m, q;

int s[MAX_N][MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    s[l][r] += 1;
  }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    }

  for (int i = 0; i < q; ++i) {
    int p, q;
    scanf("%d %d", &p, &q);

    int ans = s[q][q] - s[p - 1][q] - s[q][p - 1] + s[p - 1][p - 1];

    printf("%d\n", ans);
  }

  return 0;
}
