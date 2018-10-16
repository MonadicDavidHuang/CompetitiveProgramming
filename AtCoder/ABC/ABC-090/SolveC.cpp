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

  if (m == 1 && n == 1) {
    ans = 1;
  } else if (m == 1 && n > 1) {
    ans = n - 2;
  } else if (m > 1 && n == 1) {
    ans = m - 2;
  } else {
    ans = (n - 2) * (m - 2);
  }

  printf("%lld\n", ans);

  return 0;
}
