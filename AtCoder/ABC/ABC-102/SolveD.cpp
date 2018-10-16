#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e16 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
ll a[MAX_N];

ll acc[MAX_N];

ll ans;

// (l, r]
pair<ll, ll> find_divide(int l, int r) {
  ll whole = acc[r] - acc[l];

  ll target = whole / 2;  // around;

  int index = lower_bound(acc + l + 1, acc + r, acc[l] + target) - acc;

  ll diff = INF;

  ll left = 0LL;
  ll right = 0LL;

  for (int i = max(index - 20, l + 1); i <= min(index + 20, r); ++i) {
    ll tmp_left = acc[i] - acc[l];
    ll tmp_right = acc[r] - acc[i];

    if (abs(tmp_left - tmp_right) < diff) {
      diff = abs(tmp_left - tmp_right);
      left = tmp_left;
      right = tmp_right;
    }
  }

  return make_pair(left, right);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    acc[i] = acc[i - 1] + a[i];
  }

  ans = INF;

  for (int i = 3; i <= n; ++i) {
    if ((n - i + 1) < 2) continue;

    auto left_pair = find_divide(0, i - 1);
    auto right_pair = find_divide(i - 1, n);

    ll min_block =
        min(min(min(left_pair.first, left_pair.second), right_pair.first),
            right_pair.second);
    ll max_block =
        max(max(max(left_pair.first, left_pair.second), right_pair.first),
            right_pair.second);

    ans = min(ans, abs(max_block - min_block));
  }

  printf("%lld\n", ans);

  return 0;
}
