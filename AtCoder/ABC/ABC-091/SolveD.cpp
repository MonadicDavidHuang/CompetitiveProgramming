#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
ll mypow_core(ll x, int n, ll result) {
  if (n == 0) {
    return result;
  }

  if (n % 2 == 0) {
    return mypow_core(x * x, n / 2, result);
  } else {
    return mypow_core(x, n - 1, x * result);
  }
}

ll mypow(ll x, int n) { return mypow_core(x, n, 1); }
/////////////////////////////////////////////////////////////

const int MAX_N = (int)(2e5 + 5);

int n;
ll a[MAX_N];
ll b[MAX_N];

ll decide(int k) {
  ll t = mypow(2LL, k);

  vector<ll> ma;
  vector<ll> mb;

  for (int i = 0; i < n; ++i) {
    ma.push_back(a[i] % (2LL * t));
    mb.push_back(b[i] % (2LL * t));
  }

  sort(mb.begin(), mb.end());

  ll cnt = 0LL;

  for (auto &e : ma) {
    ll fst = upper_bound(mb.begin(), mb.end(), 2LL * t - e - 1LL) -
             lower_bound(mb.begin(), mb.end(), t - e);
    ll snd = upper_bound(mb.begin(), mb.end(), 4LL * t - e - 1LL) -
             lower_bound(mb.begin(), mb.end(), 3LL * t - e);
    cnt += fst + snd;
  }

  return cnt % 2LL;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(b[i]));
  }

  vector<ll> target_bits;

  for (int i = 0; i < 30; ++i) {
    target_bits.push_back(decide(i));
  }

  ll base = 1LL;
  ll ans = 0LL;

  for (int i = 0; i < target_bits.size(); ++i) {
    ans += target_bits[i] * base;
    base *= 2LL;
  }

  printf("%lld\n", ans);

  return 0;
}
