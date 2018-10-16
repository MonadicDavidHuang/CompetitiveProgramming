#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using elem = tuple<int, int, int>;

const int MAX_H = (int)(1e3 + 5);
const int MAX_W = (int)(1e3 + 5);

int h, w;
char a[MAX_H][MAX_W];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(a[i]));
  }

  queue<elem> que;
  set<pair<int, int>> visited;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        que.push(elem(i, j, 0));
        visited.insert(make_pair(i, j));
      }
    }
  }

  while (!que.empty()) {
    elem cur = que.front();
    que.pop();

    int x = get<0>(cur);
    int y = get<1>(cur);

    int phase = get<2>(cur);

    // printf("%d\n", phase);

    ans = phase;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (visited.find(make_pair(nx, ny)) != visited.end()) continue;
      if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;

      que.push(elem(nx, ny, phase + 1));
      visited.insert(make_pair(nx, ny));
    }
  }

  printf("%d\n", ans);

  return 0;
}
