#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2000 + 5);

ll answer, a[MAX_N];
ll n, z, w;

ll memo[MAX_N][2][MAX_N];

ll ans(int il, int f, ll cx, ll cy) {
  ll opp = (f == 0) ? cy : cx;

  if (memo[il][f][opp] != -1) return memo[il][f][opp];

  if (il == n + 2) {
    return abs(a[cx] - a[cy]);
  }

  ll tmp;
  if (f == 1) {
    tmp = INF;
    for (int i = il; i < n + 2; ++i) {
      tmp = min(tmp, ans(i + 1, 0, cx, i));
    }
  } else {
    tmp = -1;
    for (int i = il; i < n + 2; ++i) {
      tmp = max(tmp, ans(i + 1, 1, i, cy));
    }
  }

  return memo[il][f][opp] = tmp;
}

int main(void) {
  // Here your code !
  scanf("%d %lld %lld", &n, &z, &w);
  for (int i = 2; i < n + 2; ++i) {
    scanf("%lld", &(a[i]));
  }
  a[0] = z;
  a[1] = w;

  memset(memo, -1, sizeof(memo));

  answer = ans(2, 0, 0, 1);
  printf("%lld\n", answer);

  return 0;
}
