#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e12 + 5);

const int MAX_N = (int)(1e5 + 5);

int a, b, q;
ll s[MAX_N];
ll t[MAX_N];

ll calc(ll x) {
  int ind_a = upper_bound(s, s + a, x) - s;
  int ind_b = upper_bound(t, t + b, x) - t;

  vector<ll> vec_a;
  if (ind_a < a) vec_a.push_back(s[ind_a]);
  if (ind_a > 0) vec_a.push_back(s[ind_a - 1]);

  vector<ll> vec_b;
  if (ind_b < b) vec_b.push_back(t[ind_b]);
  if (ind_b > 0) vec_b.push_back(t[ind_b - 1]);

  ll ret = INF;

  for (auto &es : vec_a) {
    for (auto &et : vec_b) {
      ret = min(ret, abs(x - es) + abs(es - et));
    }
  }

  for (auto &et : vec_b) {
    for (auto &es : vec_a) {
      ret = min(ret, abs(x - et) + abs(et - es));
    }
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d", &a, &b, &q);

  for (int i = 0; i < a; ++i) {
    scanf("%lld", &(s[i]));
  }

  for (int i = 0; i < b; ++i) {
    scanf("%lld", &(t[i]));
  }

  sort(s, s + a);
  sort(t, t + b);

  for (int i = 0; i < q; ++i) {
    ll x;
    scanf("%lld", &x);

    printf("%lld\n", calc(x));
  }

  return 0;
}
