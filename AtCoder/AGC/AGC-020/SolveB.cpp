#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

ll get_high(ll high, ll target) {
  ll high_times = high / target;
  return high_times * target;
}

ll get_low(ll low, ll target) {
  ll low_times = (low + target - 1) / target;
  return low_times * target;
}

bool check_include(ll low, ll high, ll target) {
  if (high < target) {
    return false;
  }

  if (low <= target && target <= high) {
    return true;
  }

  ll low_alpha = (low + target - 1) / target;
  ll high_alpha = high / target;

  if (low_alpha > high_alpha) {
    return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  if (a[n - 1] > 2) {
    printf("%d\n", -1);
    return 0;
  }

  ll num_low = 2LL;
  ll num_high = 2LL;

  for (int i = n - 1; i >= 1; --i) {
    ll low = num_low;
    ll high = num_high + a[i] - 1LL;

    if (!check_include(low, high, a[i - 1])) {
      printf("%d\n", -1);
      return 0;
    }

    num_low = get_low(low, a[i - 1]);
    num_high = get_high(high, a[i - 1]);
  }

  printf("%lld %lld\n", num_low, num_high + a[0] - 1);

  return 0;
}
