#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
int a[MAX_N];

ll ans;

ll cost(int target) {
  ll tmp = 0;
  for (int i = 0; i < n; ++i) {
    tmp += (a[i] - target) * (a[i] - target);
  }
  return tmp;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }

  ans = INF;

  for (int target = -101; target < 101; ++target) {
    ans = min(ans, cost(target));
  }

  printf("%lld\n", ans);

  return 0;
}
