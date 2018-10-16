#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll a[MAX_N];

ll add_a[MAX_N];
ll xor_a[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    add_a[i] = add_a[i - 1] + a[i];
    xor_a[i] = xor_a[i - 1] ^ a[i];
  }

  ans = 0LL;

  for (int i = 1; i <= n; ++i) {
    int ok = i;
    int ng = n + 1;

    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;

      ll add_value = add_a[mid] - add_a[i - 1];
      ll xor_value = xor_a[mid] ^ xor_a[i - 1];

      if (add_value == xor_value) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    ans += (ll)(ok - i + 1);
  }

  printf("%lld\n", ans);

  return 0;
}
