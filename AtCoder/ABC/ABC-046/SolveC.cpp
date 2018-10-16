#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n;

ll t[MAX_N], a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(t[i]), &(a[i]));
  }

  for (int i = 1; i < n; ++i) {
    ll part_t = t[i - 1] / t[i];
    ll part_a = a[i - 1] / a[i];

    if (part_t == 0 && part_a == 0) {
      // do nothing
    } else if (part_t == 0) {
      for (ll j = part_a - 1; j < (part_a - 1 + 3); ++j) {
        if (a[i] * j >= a[i - 1]) {
          a[i] = a[i] * j;
          t[i] = t[i] * j;
          break;
        }
      }
    } else if (part_a == 0) {
      for (ll j = part_t - 1; j < (part_t - 1 + 3); ++j) {
        if (t[i] * j >= t[i - 1]) {
          a[i] = a[i] * j;
          t[i] = t[i] * j;
          break;
        }
      }
    } else {
      ll part = max(part_t, part_a);
      for (ll j = part - 1; j < (part - 1 + 3); ++j) {
        if (t[i] * j >= t[i - 1] && a[i] * j >= a[i - 1]) {
          a[i] = a[i] * j;
          t[i] = t[i] * j;
          break;
        }
      }
    }
  }

  printf("%lld\n", t[n - 1] + a[n - 1]);

  return 0;
}
