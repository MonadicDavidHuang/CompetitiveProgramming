#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll w, h, x, y;

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld %lld", &w, &h, &x, &y);

  printf("%.10lf %d\n", double(w) * double(h) / 2.0,
         2LL * x == w && 2LL * y == h);

  return 0;
}
