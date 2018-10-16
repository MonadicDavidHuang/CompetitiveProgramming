#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;
ll x, y;
ll a[MAX_N], b[MAX_M];

int ans;

int get_next_index(ll *c, int index, ll cur) {
  while (c[index] < cur) {
    if (index >= n) break;
    index += 1;
  }
  return index;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  scanf("%lld %lld", &x, &y);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < m; ++i) {
    scanf("%lld", &(b[i]));
  }

  int ia = 0, ib = 0;
  int cnt = 0;
  ll cur = 0;

  while (true) {
    if (cnt % 2 == 0) {
      if (ia >= n) break;
      while (a[ia] < cur) {
        if (ia >= n) break;
        ia += 1;
      }
      if (ia >= n) break;

      cur = a[ia];
      cur += x;
      cnt += 1;
    } else {
      if (ib >= m) break;
      while (b[ib] < cur) {
        if (ib >= m) break;
        ib += 1;
      }
      if (ib >= m) break;

      cur = b[ib];
      cur += y;
      cnt += 1;
    }
  }

  ans = cnt / 2;

  printf("%d\n", ans);

  return 0;
}
