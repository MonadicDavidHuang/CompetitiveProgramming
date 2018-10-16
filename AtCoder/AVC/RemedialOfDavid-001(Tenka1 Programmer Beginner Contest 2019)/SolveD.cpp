#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e2 + 5);
const int MAX_ELEM = (int)(3e2 + 5);
const ll MOD = (ll)(998244353);

int n;
int a[MAX_N];

ll dp_single[2][MAX_N * MAX_ELEM];
ll dp_double[2][MAX_N * MAX_ELEM];

int max_size;
int acc;

ll ans;

ll calc_whole() {
  ll ret = 1LL;
  for (int i = 0; i < n; ++i) {
    ret *= 3;
    ret %= MOD;
  }
  return ret;
}

ll calc_single() {
  dp_single[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    int last_ind = (i - 1) % 2;
    int cur_ind = i % 2;

    for (int j = 0; j <= max_size; ++j) dp_single[cur_ind][j] = 0;

    for (int j = 0; j <= max_size; ++j) {
      dp_single[cur_ind][j + a[i]] +=
          dp_single[last_ind][j];  // paint a[i] as red;
      dp_single[cur_ind][j + a[i]] %= MOD;

      dp_single[cur_ind][j] +=
          2 *
          dp_single[last_ind]
                   [j];  // paint a[i] as green or blue, sum of red don't change
      dp_single[cur_ind][j] %= MOD;
    }
  }

  int half = (acc - 1) / 2 + 1;

  int n_ind = n % 2;

  ll ret = 0LL;
  for (int i = half; i <= max_size; ++i) {
    ret += dp_single[n_ind][i];
    ret %= MOD;
  }

  return ret;
}

ll calc_double() {
  dp_double[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    int last_ind = (i - 1) % 2;
    int cur_ind = i % 2;

    for (int j = 0; j <= max_size; ++j) dp_double[cur_ind][j] = 0;

    for (int j = 0; j <= max_size; ++j) {
      dp_double[cur_ind][j + a[i]] +=
          dp_double[last_ind][j];  // paint a[i] as red;
      dp_double[cur_ind][j + a[i]] %= MOD;

      dp_double[cur_ind][j] +=
          dp_double[last_ind][j];  // paint a[i] as some-color not red, sum of
                                   // red don't change
      dp_double[cur_ind][j] %= MOD;
    }
  }

  int n_ind = n % 2;

  if (acc % 2 == 0) {
    return dp_double[n_ind][acc / 2];
  } else {
    return 0LL;
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(a[i]));
  }

  max_size = MAX_ELEM * n;
  acc = accumulate(a + 1, a + n + 1, 0);

  ll num_whole = calc_whole();
  ll num_single = calc_single();
  ll num_double = calc_double();

  ans = 0LL;

  ans += num_whole;
  ans %= MOD;

  ans -= 3 * num_single;
  ans %= MOD;

  ans += 3 * num_double;
  ans %= MOD;

  if (ans < 0) ans += MOD;

  printf("%lld\n", ans);

  return 0;
}
