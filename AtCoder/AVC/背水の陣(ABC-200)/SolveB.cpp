#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;
int k;

int main(void) {
  // Here your code !
  scanf("%lld %d", &n, &k);

  for (int i = 0; i < k; ++i) {
    if (n % 200 == 0) {
      n = n / 200;
    } else {
      n = n * 1000 + 200;
    }
  }

  printf("%lld\n", n);

  return 0;
}
