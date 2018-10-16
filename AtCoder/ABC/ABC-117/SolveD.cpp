#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_DIGIT = (int)(4e1 + 5);
const int MAX_N = (int)(1e5 + 5);

int n;
ll k;
ll a[MAX_N];

int bit_cnt[MAX_DIGIT];
ll choice[MAX_DIGIT];

vector<ll> ansvec;
ll ans = -1;

ll calc(ll x) {
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += x ^ a[i];
  }
  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAX_DIGIT; ++j) {
      if ((a[i] >> j) & 1LL) bit_cnt[j] += 1;
    }
  }

  for (int i = 0; i < MAX_DIGIT; ++i) {
    if (bit_cnt[i] > (n - bit_cnt[i])) {
      choice[i] = 0;
    } else {
      choice[i] = 1;
    }
  }

  ll kplus1 = k + 1;

  ll acc = 0;
  ll minusacc = 0;

  for (int i = 0; i < MAX_DIGIT; ++i) {
    if ((kplus1 >> i) & 1LL) {
      minusacc += (1LL << i);
      ansvec.push_back(kplus1 - minusacc + acc);
    }
    acc += (1LL << i) * choice[i];
  }

  for (auto e : ansvec) {
    ans = max(ans, calc(e));
  }

  printf("%lld\n", ans);

  return 0;
}
