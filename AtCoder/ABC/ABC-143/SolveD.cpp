#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);

ll n;
int l[MAX_N];

ll count_exclude(int i, int j) {
  int summation = l[i] + l[j];

  int index = lower_bound(l, l + n, summation) - l;

  ll part = (ll)(n - index);

  return part;
}

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(l[i]));
  }

  sort(l, l + n);

  ll whole = n * (n - 1) * (n - 2) / 6;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      whole -= count_exclude(i, j);
    }
  }

  ll ans = whole;

  printf("%lld\n", ans);

  return 0;
}
