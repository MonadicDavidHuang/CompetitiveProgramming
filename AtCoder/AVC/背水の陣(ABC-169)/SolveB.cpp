#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  sort(a, a + n);

  ll acc = 1LL;

  for (int i = 0; i < n; ++i) {
    if (a[i] == 0LL) {
      acc = 0LL;
      break;
    }

    if (a[i] > (ll)(1e18) || acc > (ll)(1e18) / a[i]) {
      acc = -1LL;
      break;
    }

    acc *= a[i];
  }

  printf("%lld\n", acc);

  return 0;
}
