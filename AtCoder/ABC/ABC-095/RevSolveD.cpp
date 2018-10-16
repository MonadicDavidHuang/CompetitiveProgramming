#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll c;

ll x[MAX_N], v[MAX_N];
ll acc_v[MAX_N];
ll fwd[MAX_N], bwd[MAX_N];

ll ans;

void prepare() {
  for (int i = 1; i <= n; ++i) {
    acc_v[i] = v[i] + acc_v[i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    fwd[i] = -1LL;
    bwd[i] = -1LL;
  }

  // clock forward
  fwd[0] = 0LL;

  for (int i = 1; i <= n; ++i) {
    ll cur = acc_v[i] - x[i];

    int last_ind = i - 1;

    fwd[i] = max(fwd[last_ind], cur);
  }

  // clock backward
  bwd[0] = 0LL;

  for (int i = n; i >= 1; --i) {
    ll cur = (acc_v[n] - acc_v[i - 1]) - (c - x[i]);

    int last_ind = (i == n) ? 0 : i + 1;

    bwd[i] = max(bwd[last_ind], cur);
  }
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &c);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &(x[i]), &(v[i]));
  }

  prepare();

  ans = -1LL;

  ans = max(ans, fwd[n]);  // only forward
  ans = max(ans, bwd[1]);  // only backward

  // forward then backward
  for (int i = 1; i <= n; ++i) {
    ll fst_cost = x[i] * 2;
    ll fst_gain = acc_v[i];

    int opposite_ind = (i == n) ? 0 : i + 1;

    ll cur = fst_gain - fst_cost + bwd[opposite_ind];

    ans = max(ans, cur);
  }

  // backward then forward
  for (int i = n; i >= 1; --i) {
    ll fst_cost = (c - x[i]) * 2;
    ll fst_gain = (acc_v[n] - acc_v[i - 1]);

    int opposite_ind = i - 1;

    ll cur = fst_gain - fst_cost + fwd[opposite_ind];

    ans = max(ans, cur);
  }

  printf("%lld\n", ans);

  return 0;
}
