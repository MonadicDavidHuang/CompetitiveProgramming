#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e15 + 5);

const int MAX_N = (int)(1e1 + 5);

ll n;
ll a[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  for (int i = 0; i < 5; ++i) {
    scanf("%lld", &(a[i]));
  }

  ll minimum = INF;

  for (int i = 0; i < 5; ++i) {
    minimum = min(minimum, a[i]);
  }

  ans = (n - 1) / minimum + 1 + 4;

  printf("%lld\n", ans);

  return 0;
}
