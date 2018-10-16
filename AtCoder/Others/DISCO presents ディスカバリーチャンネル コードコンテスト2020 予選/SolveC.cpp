#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(3e2 + 5);
const int MAX_W = (int)(3e2 + 5);

int h, w, k;
char s[MAX_H][MAX_W];

int cnt[MAX_H];
int ans[MAX_H][MAX_W];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &h, &w, &k);

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> s[i][j];
      if (s[i][j] == '#') cnt[i] += 1;
    }
  }

  int start;

  for (int i = 1; i <= h; ++i) {
    if (cnt[i] > 0) {
      start = i;
      break;
    }
  }

  int p = 0;

  for (int i = start; i <= h; ++i) {
    if (cnt[i] == 0) {
      for (int j = 1; j <= w; ++j) {
        ans[i][j] = ans[i - 1][j];
      }
      continue;
    }

    p += 1;

    for (int j = 1; j <= w; ++j) {
      ans[i][j] = p;
      if (s[i][j] == '#') {
        cnt[i] -= 1;
        if (cnt[i] > 0) p += 1;
      }
    }
  }

  for (int i = start - 1; i >= 1; --i) {
    for (int j = 1; j <= w; ++j) {
      ans[i][j] = ans[i + 1][j];
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
