#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

ll ax, ay;
ll bx, by;

int n;

ll x[MAX_N], y[MAX_N];

ll ans;

bool check(ll cx, ll cy, ll dx, ll dy) {
  ll r1 = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
  ll r2 = (bx - ax) * (dy - ay) - (by - ay) * (dx - ax);
  ll l1 = (dx - cx) * (ay - cy) - (dy - cy) * (ax - cx);
  ll l2 = (dx - cx) * (by - cy) - (dy - cy) * (bx - cx);
  return r1 * r2 < 0 && l1 * l2 < 0;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld %lld", &ax, &ay, &bx, &by);

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(x[i]), &(y[i]));
  }

  ll cnt = 0;

  if (check(x[0], y[0], x[n - 1], y[n - 1])) cnt += 1;

  for (int i = 0; i < n - 1; ++i) {
    int j = i + 1;
    if (check(x[i], y[i], x[j], y[j])) cnt += 1;
  }

  ans = cnt / 2 + 1;

  printf("%lld\n", ans);

  return 0;
}
