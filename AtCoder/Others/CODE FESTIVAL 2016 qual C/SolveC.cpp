#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n;
ll t[MAX_N];
ll a[MAX_N];

bool et[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(t[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  if (t[n - 1] != a[0]) {
    printf("%d\n", 0);
    return 0;
  }

  et[0] = true;

  for (int i = 1; i < n; ++i) {
    if (t[i] > t[i - 1]) {
      et[i] = true;
    } else {  // t[i] == t[i - 1]
      et[i] = false;
    }
  }

  ll ans = 1LL;

  for (int i = n - 2; i >= 0; --i) {
    if (a[i] > a[i + 1]) {  // i-th height must be exact from a's sight
      if (et[i]) {          // both are exact
        if (a[i] != t[i]) {
          ans = 0LL;
          break;
        } else {
          ans *= 1LL;
          ans %= MOD;
        }
      } else {              // a is exact, t is not exact
        if (a[i] > t[i]) {  // since a is exact, t must be bigger than a
          ans = 0LL;
          break;
        } else {
          ans *= 1LL;
          ans %= MOD;
        }
      }
    } else {                // a[i] == a[i + 1]
      if (et[i]) {          // t is exact, a is not exact
        if (a[i] < t[i]) {  // since t is exact, a must be bigger than t
          ans = 0LL;
          break;
        } else {
          ans *= 1LL;
          ans %= MOD;
        }
      } else {  // t is not exact
        ans *= min(a[i], t[i]);
        ans %= MOD;
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
