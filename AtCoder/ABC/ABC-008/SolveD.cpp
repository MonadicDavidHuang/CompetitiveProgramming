#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e1 + 5);

int w, h;
int n;
int x[MAX_N], y[MAX_N];

map<tuple<int, int, int, int>, int> memo;

int ans;

int rec(int xl, int xr, int yd, int yp) {
  auto key = make_tuple(xl, xr, yd, yp);

  if (memo.find(key) != memo.end()) return memo[key];

  if (xl >= xr || yd >= yp) return memo[key] = 0;

  vector<int> cand;

  for (int i = 0; i < n; ++i) {
    if (xl <= x[i] && x[i] < xr && yd <= y[i] && y[i] < yp) cand.push_back(i);
  }

  int base_earn = xr - xl + yp - yd - 1;

  int max_earn = base_earn;

  if (cand.empty()) return memo[key] = 0;

  for (auto i : cand) {
    int tmp_earn = base_earn;
    tmp_earn += rec(xl, x[i], yd, y[i]);          // left bottom
    tmp_earn += rec(xl, x[i], y[i] + 1, yp);      // left top
    tmp_earn += rec(x[i] + 1, xr, y[i] + 1, yp);  // right top
    tmp_earn += rec(x[i] + 1, xr, yd, y[i]);      // right bottom

    max_earn = max(max_earn, tmp_earn);
  }

  return memo[key] = max_earn;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &w, &h);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(x[i]), &(y[i]));
  }

  ans = rec(1, w + 1, 1, h + 1);

  printf("%d\n", ans);

  return 0;
}
