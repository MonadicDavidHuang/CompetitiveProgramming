#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using cost_grid = tuple<ll, int, int>;

const int MAX_H = (int)(1e1 + 5);
const int MAX_W = (int)(1e1 + 5);

int h, w;
ll t;
char field[MAX_H][MAX_W];

ll dist[MAX_H][MAX_W];

int sx, sy;
int gx, gy;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(ll black_cost) {
  for (int i = 0; i < h + 3; ++i) {
    fill_n(dist[i], w + 3, INF);
  }

  priority_queue<cost_grid, vector<cost_grid>, greater<cost_grid>> pque;
  set<pair<int, int>> visited;

  cost_grid start = make_tuple(0LL, sx, sy);
  pque.push(start);

  ll last_path;

  while (!pque.empty()) {
    cost_grid cur = pque.top();
    pque.pop();

    ll path = get<0>(cur);
    int x = get<1>(cur);
    int y = get<2>(cur);

    if (visited.find(make_pair(x, y)) != visited.end()) continue;
    visited.insert(make_pair(x, y));

    dist[x][y] = path;

    if (x == gx && y == gy) {
      last_path = path;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;

      ll cur_cost = (field[nx][ny] == '#') ? black_cost : 1LL;

      if (dist[nx][ny] > path + cur_cost) {
        pque.push(make_tuple(path + cur_cost, nx, ny));
      }
    }
  }

  return (last_path <= t);
}

int main(void) {
  // Here your code !
  scanf("%d %d %lld", &h, &w, &t);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(field[i]));
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (field[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (field[i][j] == 'G') {
        gx = i;
        gy = j;
      }
    }
  }

  field[sx][sy] = '.';
  field[gx][gy] = '.';

  ll ok = 1;
  ll ng = (ll)(1e9);

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2;
    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  printf("%lld\n", ok);

  return 0;
}
