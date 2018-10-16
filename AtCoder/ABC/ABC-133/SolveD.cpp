#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

ll a[MAX_N];

ll ans[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  ll acc = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (i % 2 == 0)
      acc += a[i];
    else
      acc -= a[i];
  }

  ans[0] = acc + a[n - 1];

  for (int i = 1; i < n; ++i) {
    ans[i] = 2 * (a[i - 1] - ans[i - 1] / 2);
  }

  for (int i = 0; i < n; ++i) {
    printf("%lld ", ans[i]);
  }

  printf("\n");

  return 0;
}
