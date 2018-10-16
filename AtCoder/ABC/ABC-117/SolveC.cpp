#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;

vector<int> grids;
vector<int> diffs;

int ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  if (n >= m) {
    printf("%d\n", 0);
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    int cur;
    scanf("%d", &cur);
    grids.push_back(cur);
  }

  sort(grids.begin(), grids.end());

  for (int i = 1; i < grids.size(); ++i) {
    diffs.push_back(grids[i] - grids[i - 1]);
  }

  sort(diffs.begin(), diffs.end(), greater<int>());

  // n < m
  for (int i = n - 1; i < diffs.size(); ++i) {
    ans += diffs[i];
  }

  printf("%d\n", ans);

  return 0;
}
