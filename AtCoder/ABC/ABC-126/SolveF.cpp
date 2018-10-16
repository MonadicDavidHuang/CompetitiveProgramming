#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int m;
ll k;

int main(void) {
  // Here your code !
  scanf("%d", &m);
  scanf("%lld", &k);

  if (k >= 1LL << m) {
    printf("%d\n", -1);

    return 0;
  }

  if (m == 1) {
    if (k == 1) {
      printf("%d\n", -1);
    } else {
      printf("0 0 1 1\n");
    }

    return 0;
  }

  vector<ll> base;

  for (ll i = 0; i < 1LL << m; ++i) {
    base.push_back(i);
  }

  for (auto e : base) {
    if (e == k) continue;

    printf("%lld ", e);
  }

  printf("%lld ", k);

  reverse(base.begin(), base.end());

  for (auto e : base) {
    if (e == k) continue;

    printf("%lld ", e);
  }

  printf("%lld ", k);

  printf("\n");

  return 0;
}
