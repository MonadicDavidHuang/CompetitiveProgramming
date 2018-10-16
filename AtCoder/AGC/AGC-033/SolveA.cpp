#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(1e3 + 5);
const int MAX_W = (int)(1e3 + 5);

int h, w;
char a[MAX_H][MAX_W];

int ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool check() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '.') {
        return false;
      }
    }
  }
  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(a[i]));
  }

  queue<pair<int, int>> que;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') que.push(make_pair(i, j));
    }
  }

  // for (int i = 0; i < h; ++i) {
  //   for (int j = 0; j < w; ++j) {
  //     printf("%c", a[0][i][j]);
  //   }
  //   printf("\n");
  // }

  int cnt = 0;

  if (check()) {
    printf("%d\n", 0);
    return 0;
  }

  for (int i = 0;; ++i) {
    if (cnt == h * w) {
      ans = i - 1;
      break;
    }

    queue<pair<int, int>> que_next;

    while (!que.empty()) {
      auto cur = que.front();
      que.pop();

      int cur_i = cur.first;
      int cur_j = cur.second;

      cnt += 1;

      for (int k = 0; k < 4; ++k) {
        int ni = cur_i + dx[k];
        int nj = cur_j + dy[k];

        if (a[ni][nj] == '#') continue;
        if (!(0 <= ni && ni < h && 0 <= nj && nj < w)) continue;

        a[ni][nj] = '#';
        que_next.push(make_pair(ni, nj));
      }
    }

    que = que_next;
  }

  printf("%d\n", ans);

  return 0;
}
