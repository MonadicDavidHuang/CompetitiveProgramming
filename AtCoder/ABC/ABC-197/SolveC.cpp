#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(20 + 5);

int n;
ll a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  int m = n;

  ll ans = INF;

  for (int e = 0; e < (1 << (m - 1)); ++e) {
    int bit = e | (1 << (m - 1));

    ll cur_cand = 0LL;

    ll cur = 0LL;

    for (int i = 0; i < m; ++i) {
      cur = cur | a[i];

      if ((bit >> i) & 1) {
        cur_cand = cur_cand ^ cur;
        cur = 0LL;
      }
    }

    ans = min(ans, cur_cand);
  }

  printf("%lld\n", ans);

  return 0;
}
