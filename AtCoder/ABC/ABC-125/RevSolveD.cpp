#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

ll a[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) cnt += 1;
  }

  ll whole = 0LL;
  ll min_a = INF;

  for (int i = 0; i < n; ++i) {
    whole += abs(a[i]);
    min_a = min(min_a, abs(a[i]));
  }

  if (cnt % 2 == 0) {
    ans = whole;
  } else {
    ans = whole - 2 * min_a;
  }

  printf("%lld\n", ans);

  return 0;
}
