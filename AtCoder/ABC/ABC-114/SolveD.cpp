#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

map<int, int> cnt;
map<int, int> acc;

ll ans;

/////////////////////////////////////////////////////////////
map<ll, ll> prime_factorization(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res[i] += 1;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  map<ll, ll> whole;

  for (int i = 1; i <= n; ++i) {
    map<ll, ll> tmp = prime_factorization(i);

    for (auto itr = tmp.begin(); itr != tmp.end(); ++itr) {
      whole[itr->first] += itr->second;
    }
  }

  ll max_ind = 0;

  for (auto itr = whole.begin(); itr != whole.end(); ++itr) {
    cnt[itr->second] += 1;
    max_ind = max(max_ind, itr->second);
  }

  for (int i = max_ind; i >= 0; --i) {
    acc[i] = 0;
  }

  acc[max_ind] = cnt[max_ind];

  for (int i = max_ind - 1; i >= 0; --i) {
    acc[i] = acc[i + 1] + cnt[i];
  }

  ans += acc[74];
  ans += acc[24] * max(0, (acc[2] - 1));
  ans += acc[14] * max(0, (acc[4] - 1));
  ans += acc[4] * max(0, (acc[4] - 1)) * max(0, (acc[2] - 2)) / 2;

  printf("%lld\n", ans);

  return 0;
}
