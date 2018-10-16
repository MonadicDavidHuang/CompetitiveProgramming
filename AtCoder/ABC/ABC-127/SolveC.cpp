#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, m;

int imos[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);

    imos[l] += 1;
    imos[r + 1] -= 1;
  }

  for (int i = 1; i <= n; ++i) {
    imos[i] += imos[i - 1];
  }

  int cnt = 0;

  for (int i = 1; i <= n; ++i) {
    if (imos[i] == m) {
      cnt += 1;
    }
  }
  ans = cnt;

  printf("%d\n", ans);

  return 0;
}
