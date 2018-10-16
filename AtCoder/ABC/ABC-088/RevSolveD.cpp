#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(5e1 + 5);
const int MAX_W = (int)(5e1 + 5);

int h, w;
char s[MAX_H][MAX_W];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

ll path[MAX_H][MAX_W];

void calc_path() {
  queue<pair<int, int>> que;

  que.push(make_pair(0, 0));
  path[0][0] = 0LL;

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    ll cur_cost = path[cur.first][cur.second];

    for (int i = 0; i < 4; ++i) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
      if (s[nx][ny] == '#') continue;
      if (path[nx][ny] < INF) continue;

      path[nx][ny] = cur_cost + 1LL;

      que.push(make_pair(nx, ny));
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", s[i]);
  }

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      path[i][j] = INF;
    }

  calc_path();

  if (path[h - 1][w - 1] == INF) {
    printf("-1\n");
    return 0;
  }

  int cnt = 0;

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') cnt += 1;
    }

  int ans = cnt - (int)(path[h - 1][w - 1] + 1LL);

  printf("%d\n", ans);

  return 0;
}
