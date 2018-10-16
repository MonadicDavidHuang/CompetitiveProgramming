#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll x, y;

int main(void) {
  // Here your code !
  scanf("%lld %lld", &x, &y);

  printf("%lld\n", max(x, y));

  return 0;
}
