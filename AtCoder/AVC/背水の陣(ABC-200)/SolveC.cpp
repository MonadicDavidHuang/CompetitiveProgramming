#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll a[MAX_N];

ll modulo[200];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  for (int i = 0; i < 200; ++i) {
    modulo[i] = 0LL;
  }

  for (int i = 0; i < n; ++i) {
    int key = (int)(a[i] % 200LL);
    modulo[key] += 1LL;
  }

  ll ans = 0LL;

  for (int i = 0; i < n; ++i) {
    int key = (int)(a[i] % 200LL);
    ans += modulo[key] - 1LL;
  }

  ans /= 2LL;

  printf("%lld\n", ans);

  return 0;
}
