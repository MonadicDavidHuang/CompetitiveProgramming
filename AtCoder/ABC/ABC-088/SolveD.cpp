#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using gridcost = tuple<int, int, int>;

const int MAX_H = (int)(1e2 + 5);
const int MAX_W = (int)(1e2 + 5);

int h, w;
char s[MAX_H][MAX_W];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<pair<int, int>> visited;

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(s[i]));
  }

  int white = 0;

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') white += 1;
    }

  int length = -1;

  queue<gridcost> que;

  que.push(gridcost(0, 0, 0));
  visited.insert(make_pair(0, 0));

  while (!que.empty()) {
    gridcost tmp = que.front();
    que.pop();

    int x = get<0>(tmp);
    int y = get<1>(tmp);
    int cost = get<2>(tmp);

    if (x == (h - 1) && y == (w - 1)) {
      length = cost;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (s[nx][ny] == '#') continue;
      if (visited.find(make_pair(nx, ny)) != visited.end()) continue;

      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        que.push(gridcost(nx, ny, cost + 1));
        visited.insert(make_pair(nx, ny));
      }
    }
  }

  if (length == -1) {
    printf("%d\n", -1);
  } else {
    ans = white - (length + 1);
    printf("%d\n", ans);
  }

  return 0;
}
