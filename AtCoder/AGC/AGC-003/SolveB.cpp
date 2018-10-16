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

  for (int i = 1; i <= n; ++i) {
    ll tmp;
    scanf("%lld", &(a[i]));
  }

  vector<int> idx;

  ll ans = 0LL;

  for (int i = 1; i <= n; ++i) {
    {  // about i;
      ll commit = a[i] / 2LL;
      ans += commit;
      a[i] -= 2LL * commit;
    }

    {  // about i and (i + 1)
      ll commit = min(a[i], a[i + 1]);

      ans += commit;

      a[i] -= commit;
      a[i + 1] -= commit;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
