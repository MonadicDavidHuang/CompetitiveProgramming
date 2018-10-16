#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int k;

int main(void) {
  // Here your code !
  scanf("%d", &k);

  ll a = 1LL, b = 0LL;
  for (int i = 0; i < k; ++i) {
    ll nb = a;
    ll na = b + nb;

    if (na == a) na += nb;

    a = na;
    b = nb;
  }

  printf("%lld %lld\n", a, b);

  return 0;
}
