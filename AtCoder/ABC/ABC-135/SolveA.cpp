#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll a, b;

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &a, &b);

  if (abs(a - b) % 2 == 1) {
    printf("IMPOSSIBLE\n");
    return 0;
  }

  ans = min(a, b) + (abs(a - b) / 2);

  printf("%lld\n", ans);

  return 0;
}
