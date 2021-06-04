#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
ll d;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &d);

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    if ((x * x + y * y) <= d * d) {
      ans += 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
