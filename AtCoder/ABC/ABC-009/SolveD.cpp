#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using matrix = vector<vector<ll>>;

const int MAX_K = (int)(1e2 + 5);
const int MAX_LOG_M = (int)(log2(1e9 + 5) + 5);

ll k, m;

ll a[MAX_K];
ll c[MAX_K];

vector<matrix> w_vec;

matrix matmul(matrix &a, matrix &b) {
  matrix ret(k, vector<ll>(k));

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int s = 0; s < k; ++s) {
        ret[i][j] ^= (a[i][s] & b[s][j]);
      }
    }
  }

  return ret;
}

void make_doubling(int log2m, ll k) {
  matrix init_w(k, vector<ll>(k));

  for (ll i = 0; i < k; ++i) {
    init_w[0][i] = c[i];
  }

  for (ll i = 0; i < k - 1; ++i) {
    init_w[i + 1][i] = ~0LL;
  }

  w_vec.push_back(init_w);

  for (int i = 1; i <= log2m; ++i) {
    auto cur_w = matmul(w_vec.back(), w_vec.back());
    w_vec.push_back(cur_w);
  }
}

vector<int> calc_keys(int log2m, ll target) {
  vector<ll> cand;

  cand.push_back(1LL);

  for (int i = 0; i <= log2m; ++i) {
    cand.push_back(cand.back() * 2);
  }

  vector<int> keys;

  for (int i = cand.size() - 1; i >= 0; --i) {
    if (target >= cand[i]) {
      target -= cand[i];
      keys.push_back(i);
    }
  }

  return keys;
}

ll do_run(vector<int> keys, ll *arr) {
  vector<ll> last(k);
  for (ll i = 0; i < k; ++i) {
    last[i] = arr[k - 1 - i];
  }

  for (auto key : keys) {
    vector<ll> cur(k);

    for (ll i = 0; i < k; ++i) {
      for (ll s = 0; s < k; ++s) {
        cur[i] ^= (w_vec[key][i][s] & last[s]);
      }
    }

    last = cur;
  }

  return last[0];
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &k, &m);

  for (ll i = 0; i < k; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (ll i = 0; i < k; ++i) {
    scanf("%lld", &(c[i]));
  }

  if (m <= k) {
    printf("%lld\n", a[m - 1]);
    return 0;
  }

  int log2m = (int)(log2(m) + 3);

  make_doubling(log2m, k);

  auto keys = calc_keys(log2m, m - k);

  ll ans = do_run(keys, a);

  printf("%lld\n", ans);

  return 0;
}
