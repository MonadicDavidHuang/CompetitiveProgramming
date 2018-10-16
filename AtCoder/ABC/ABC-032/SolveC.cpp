#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, k;
ll s[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(s[i]));
  }

  s[n] = k + 1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 0) {
      printf("%d\n", n);
      return 0;
    }
  }

  int r = 0;
  ll acc = 1;

  ans = 0;

  for (int l = 0; l < n; ++l) {
    while (r < n && (acc * s[r]) <= k) {
      acc *= s[r];
      r += 1;
    }

    ans = max(ans, r - l);

    if (l == r) {
      r += 1;
    } else {
      acc /= s[l];
    }
  }

  printf("%d\n", ans);

  return 0;
}
