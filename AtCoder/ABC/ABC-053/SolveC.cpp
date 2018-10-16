#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll x;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld", &x);

  ll tmp = x / 11;

  if (x % 11 == 0) {
    ans = tmp * 2;
  } else if (tmp * 11 + 5 >= x || tmp * 11 + 6 >= x) {
    ans = tmp * 2 + 1;
  } else {
    ans = tmp * 2 + 2;
  }

  printf("%lld\n", ans);

  return 0;
}
