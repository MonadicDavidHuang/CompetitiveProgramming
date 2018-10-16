#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_R = (int)(1e3 + 5);
const int MAX_C = (int)(1e3 + 5);

int r, c, k;

char s[MAX_R][MAX_C];

int si[MAX_R][MAX_C];
int accsi[MAX_R][MAX_C];

int ans;

bool check(int x, int y) {
  for (int cx = x - (k - 1); cx <= x + (k - 1); ++cx) {
    if (si[cx][y] == 1) return false;

    int remain = k - 1 - abs(x - cx);
    int left = y - remain;
    int right = y + remain;

    int diff = accsi[cx][right] - accsi[cx][left - 1];
    bool cond = (si[cx][left] == 0 && si[cx][right] == 0 && diff == 0);

    if (!cond) return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d", &r, &c, &k);

  for (int i = 0; i < r; ++i) {
    scanf("%s", &(s[i]));
  }

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      if (s[i][j] == 'x') {
        si[i + 1][j + 1] = 1;
      }
    }

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      accsi[i][j] += accsi[i][j - 1] + si[i][j];
    }
  }

  for (int i = k; i <= r - k + 1; ++i)
    for (int j = k; j <= c - k + 1; ++j) {
      if (check(i, j)) ans += 1;
    }

  printf("%d\n", ans);

  return 0;
}
