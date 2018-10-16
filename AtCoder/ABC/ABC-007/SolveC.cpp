#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using grid_score = tuple<int, int, int>;
using grid = pair<int, int>;

const int MAX_R = (int)(5e1 + 5);
const int MAX_C = (int)(5e1 + 5);

int r, c;
int sx, sy;
int gx, gy;

char field[MAX_R][MAX_C];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &r, &c);
  scanf("%d %d", &sx, &sy);
  scanf("%d %d", &gx, &gy);

  for (int i = 0; i < r; ++i) {
    scanf("%s", field[i]);
  }

  grid_score start = make_tuple(sx - 1, sy - 1, 0);

  queue<grid_score> que;
  set<grid> visited;

  que.push(start);
  visited.insert(make_pair(get<0>(start), get<1>(start)));

  int path = -1;

  while (!que.empty()) {
    grid_score cur = que.front();
    que.pop();

    int cur_x = get<0>(cur);
    int cur_y = get<1>(cur);
    int cur_score = get<2>(cur);

    if (cur_x == (gx - 1) && cur_y == (gy - 1)) {
      path = cur_score;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int next_x = cur_x + dx[i];
      int next_y = cur_y + dy[i];

      if (visited.find(make_pair(next_x, next_y)) != visited.end()) continue;

      if (!(0 <= next_x && next_x < r && 0 <= next_y && next_y < c)) continue;

      if (field[next_x][next_y] == '#') continue;

      que.push(make_tuple(next_x, next_y, cur_score + 1));
      visited.insert(make_pair(next_x, next_y));
    }
  }

  ans = path;

  printf("%d\n", ans);

  return 0;
}
