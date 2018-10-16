#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll h, w;

ll ans = INF;

int main(void) {
  // Here your code !
  scanf("%lld %lld\n", &h, &w);

  for (ll i = 1; i < h; ++i) {
    ll mid = (i + h) / 2;

    ll cur_base = w * i;

    for (ll j = max(mid - 2, i); j <= min(mid + 2, h); ++j) {
      ll cur_1 = (j - i) * w;
      ll cur_2 = (h - j) * w;

      ll cur_diff =
          max(cur_base, max(cur_1, cur_2)) - min(cur_base, min(cur_1, cur_2));

      ans = min(ans, cur_diff);
    }
  }

  for (ll i = 1; i < h; ++i) {
    ll mid = w / 2;

    ll cur_base = w * i;

    for (ll j = max(mid - 2, 0LL); j <= min(mid + 2, w); ++j) {
      ll cur_1 = (h - i) * j;
      ll cur_2 = (h - i) * (w - j);

      ll cur_diff =
          max(cur_base, max(cur_1, cur_2)) - min(cur_base, min(cur_1, cur_2));

      ans = min(ans, cur_diff);
    }
  }

  for (ll i = 1; i < w; ++i) {
    ll mid = (i + w) / 2;

    ll cur_base = h * i;

    for (ll j = max(mid - 2, i); j <= min(mid + 2, w); ++j) {
      ll cur_1 = h * (j - i);
      ll cur_2 = h * (w - j);

      ll cur_diff =
          max(cur_base, max(cur_1, cur_2)) - min(cur_base, min(cur_1, cur_2));

      ans = min(ans, cur_diff);
    }
  }

  for (ll i = 1; i < w; ++i) {
    ll mid = h / 2;

    ll cur_base = h * i;

    for (ll j = max(mid - 2, 0LL); j <= min(mid + 2, h); ++j) {
      ll cur_1 = j * (w - i);
      ll cur_2 = (h - j) * (w - i);

      ll cur_diff =
          max(cur_base, max(cur_1, cur_2)) - min(cur_base, min(cur_1, cur_2));

      ans = min(ans, cur_diff);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
