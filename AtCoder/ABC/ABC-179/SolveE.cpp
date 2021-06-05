#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n, x, m;

unordered_map<ll, ll> val2ind;

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld", &n, &x, &m);

  ll a = x;

  val2ind[a] = 0LL;

  ll acc = 0;
  acc += a;

  ll begin_ind = -1;
  ll end_ind = -1;
  ll init_val = -1;

  for (ll i = 1LL; i < n; ++i) {
    a = (a * a) % m;

    if (val2ind.find(a) != val2ind.end()) {
      begin_ind = val2ind[a];
      end_ind = i - 1;
      init_val = a;
      break;
    }

    val2ind[a] = i;
    acc += a;
  }

  ll ans;

  if (init_val < 0) {
    ans = acc;
  } else {
    ll bottom_size = begin_ind - 0;
    ll chunk_size = end_ind - begin_ind + 1;

    ll bottom = 0LL;
    if (bottom_size > 0) {
      bottom += x;
      ll tmp = x;
      for (ll i = 1LL; i < begin_ind; ++i) {
        tmp = (tmp * tmp) % m;
        bottom += tmp;
      }
    }

    ll chunk = acc - bottom;

    ll to_be_chunked = n - bottom_size;
    ll num_chunk = to_be_chunked / chunk_size;
    ll remain_size = to_be_chunked % chunk_size;

    ll remain = 0LL;
    if (remain_size > 0) {
      remain += init_val;
      ll b = init_val;
      for (ll i = 1LL; i < remain_size; ++i) {
        b = (b * b) % m;
        remain += b;
      }
    }

    ans = bottom + (num_chunk * chunk) + remain;
  }

  printf("%lld\n", ans);

  return 0;
}
