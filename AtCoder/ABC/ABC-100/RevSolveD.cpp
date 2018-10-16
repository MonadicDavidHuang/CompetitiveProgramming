#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n, m;
ll x[MAX_N];
ll y[MAX_N];
ll z[MAX_N];

ll d[2] = {-1LL, 1LL};

ll ans;

ll calc(vector<ll> &cur) {
  sort(cur.begin(), cur.end(), greater<ll>());

  ll ret = 0LL;

  for (int i = 0; i < m; ++i) {
    ret += cur[i];
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld %lld", &(x[i]), &(y[i]), &(z[i]));
  }

  ans = -1LL;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        vector<ll> cur;

        for (int l = 0; l < n; ++l) {
          cur.push_back(d[i] * x[l] + d[j] * y[l] + d[k] * z[l]);
        }

        ans = max(ans, calc(cur));
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
