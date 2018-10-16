#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n, k;
ll v[MAX_N];
ll acc_v[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(v[i]));
  }

  ans = -1;

  for (int f = 0; f <= n; ++f) {
    for (int b = 0; b <= n; ++b) {
      int f_ind = f;
      int b_ind = n + 1 - b;

      if (f_ind >= b_ind) continue;
      if (f + b > k) continue;

      ll whole = 0;
      vector<ll> negative;
      for (int i = 1; i <= f_ind; ++i) {
        whole += v[i];
        if (v[i] < 0) {
          negative.push_back(v[i]);
        }
      }

      for (int i = n; i >= b_ind; --i) {
        whole += v[i];
        if (v[i] < 0) {
          negative.push_back(v[i]);
        }
      }

      int remain = k - (f + b);

      sort(negative.begin(), negative.end());

      int size = min(remain, (int)(negative.size()));

      // printf("%d %d: %lld :", f_ind, b_ind, whole);
      //
      // for (auto e: negative) {
      //   printf("%lld ", e);
      // }
      // printf("\n");

      for (int i = 0; i < size; ++i) {
        whole -= negative[i];
      }

      ans = max(ans, whole);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
