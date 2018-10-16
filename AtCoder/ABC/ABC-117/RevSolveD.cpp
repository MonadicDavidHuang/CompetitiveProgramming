#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_LOG = (int)(4e1 + 5);

int n;
ll k;
vector<ll> vec_a;

int cnt[MAX_LOG];
int best[MAX_LOG];

ll ans;

ll calc(ll x) {
  ll ret = 0LL;

  for (auto &a : vec_a) {
    ret += x ^ a;
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    ll a;
    scanf("%lld", &a);
    vec_a.push_back(a);
  }

  for (auto &a : vec_a) {
    for (int i = 0; i < MAX_LOG; ++i) {
      if (a >> i & 1LL) cnt[i] += 1;
    }
  }
  for (int i = 0; i < MAX_LOG; ++i) {
    int cnt_1 = cnt[i];
    int cnt_0 = n - cnt[i];

    if (cnt_1 >= cnt_0)
      best[i] = 0;
    else
      best[i] = 1;
  }

  ans = calc(k);

  for (int i = 0; i < MAX_LOG; ++i) {
    if (k >> i & 1LL) {
      vector<int> tmp(MAX_LOG);

      for (int j = 0; j < i; ++j) {
        tmp[j] = best[j];
      }

      tmp[i] = 0;

      for (int j = i + 1; j < MAX_LOG; ++j) {
        tmp[j] = (k >> j & 1) ? 1 : 0;
      }

      ll x = 0LL;

      for (int j = 0; j < MAX_LOG; ++j) {
        x += (ll)(tmp[j]) * 1LL << j;
      }

      ans = max(ans, calc(x));
    }
  }

  printf("%lld\n", ans);

  return 0;
}
