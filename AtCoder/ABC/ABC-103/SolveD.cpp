#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_M = (int)(1e5 + 5);

int n, m;

vector<pair<int, int>> claims;

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    claims.push_back(make_pair(b, a));
  }

  sort(claims.begin(), claims.end());

  int pos = 0;

  ans = 0;

  for (auto &e : claims) {
    if (pos <= e.second) {
      pos = e.first;
      ans += 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
