#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(1e2 + 5);
const int MAX_W = (int)(1e1 + 5);
const ll MOD = (ll)(1e9 + 7);

int h, w, k;

ll dp[MAX_H][MAX_W];
ll mv[MAX_W][3];
int retain = 0, ls = 1, rs = 2;
bool arr[MAX_W];

ll ans;

bool check() {
  for (int l = 1; l <= w - 1; ++l) {
    if (arr[l] && arr[l + 1]) {
      return false;
    }
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d", &h, &w, &k);

  arr[0] = false;  // guard

  for (int k = 0; k < 1 << (w - 1); ++k) {
    for (int l = 0; l < w - 1; ++l) {
      arr[l + 1] = (k >> l & 1) ? true : false;
    }

    if (!check()) continue;  // in-valid pattern

    for (int j = 1; j <= w; ++j) {
      if (arr[j]) {
        mv[j][rs] += 1;
      } else if (arr[j - 1]) {
        mv[j][ls] += 1;
      } else {
        mv[j][retain] += 1;
      }
    }
  }

  dp[0][1] = 1LL;

  for (int i = 0; i < h; ++i) {
    for (int j = 1; j <= w; ++j) {
      dp[i + 1][j] += dp[i][j] * mv[j][retain];
      dp[i + 1][j + 1] += dp[i][j] * mv[j][rs];
      dp[i + 1][j - 1] += dp[i][j] * mv[j][ls];

      dp[i + 1][j] %= MOD;
      dp[i + 1][j + 1] %= MOD;
      dp[i + 1][j - 1] %= MOD;
    }
  }

  ans = dp[h][k];

  printf("%lld\n", ans);

  return 0;
}
