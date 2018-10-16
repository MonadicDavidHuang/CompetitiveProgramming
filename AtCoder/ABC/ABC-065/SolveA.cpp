#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll x, a, b;

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld", &x, &a, &b);

  if (a >= b) {
    printf("delicious\n");
  } else {
    if ((b - a) <= x) {
      printf("safe\n");
    } else {
      printf("dangerous\n");
    }
  }

  return 0;
}
