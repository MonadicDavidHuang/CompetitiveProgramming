#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;

int a[MAX_M];
bool used[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d", &(a[i]));
  }

  fill(used, used + n, false);

  vector<int> ans;

  for (int i = m - 1; i >= 0; --i) {
    if (used[a[i]]) continue;

    ans.push_back(a[i]);
    used[a[i]] = true;
  }

  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    ans.push_back(i);
  }

  for (auto &e : ans) {
    printf("%d\n", e);
  }

  return 0;
}
