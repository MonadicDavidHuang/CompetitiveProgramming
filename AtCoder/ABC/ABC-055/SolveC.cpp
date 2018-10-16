#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n, m;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &m);

  if (m >= 2 * n) {
    ans = n + (m - 2 * n) / 4;
  } else {
    ans = m / 2;
  }

  printf("%lld\n", ans);

  return 0;
}
