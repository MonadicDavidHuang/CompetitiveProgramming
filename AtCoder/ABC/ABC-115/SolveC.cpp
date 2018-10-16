#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, k;

ll h[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d\n", &(h[i]));
  }

  sort(h, h + n);

  ans = INF;

  for (int i = 0; i + k - 1 < n; ++i) {
    ans = min(ans, h[i + k - 1] - h[i]);
  }

  printf("%lld\n", ans);

  return 0;
}
