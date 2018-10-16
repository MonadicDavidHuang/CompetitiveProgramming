#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);
const int MAX_C = (int)(3e1 + 5);

int n, c;

int d_arr[MAX_C][MAX_C], c_arr[MAX_N][MAX_N];

int cnt[3 + 5][MAX_C];

ll ans = INF;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &c);
  for (int i = 1; i <= c; ++i)
    for (int j = 1; j <= c; ++j) {
      scanf("%d", &(d_arr[i][j]));
    }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &(c_arr[i][j]));
    }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      cnt[(i + j) % 3][c_arr[i][j]] += 1;
    }

  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= c; ++j) {
      if (i == j) continue;
      for (int k = 1; k <= c; ++k) {
        if (i == k || j == k) continue;

        ll tmp = 0;

        for (int l = 1; l <= c; ++l) {
          tmp += cnt[0][l] * d_arr[l][i];
        }

        for (int l = 1; l <= c; ++l) {
          tmp += cnt[1][l] * d_arr[l][j];
        }

        for (int l = 1; l <= c; ++l) {
          tmp += cnt[2][l] * d_arr[l][k];
        }

        ans = min(ans, tmp);
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
