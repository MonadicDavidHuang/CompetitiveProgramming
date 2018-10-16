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
    scanf("%lld", &(a[i]));
  }

  sort(a, a + n);

  ll fst = a[n - 1];

  ll max_elem = fst / 2;

  ll snd = -1LL;

  for (int i = 0; i < n; ++i) {
    ll other = fst - a[i];

    if (max_elem >= a[i]) {
      snd = max(snd, a[i]);
    }

    if (max_elem >= other && other > snd) {
      snd = a[i];
    }
  }

  printf("%lld %lld\n", fst, snd);

  return 0;
}
