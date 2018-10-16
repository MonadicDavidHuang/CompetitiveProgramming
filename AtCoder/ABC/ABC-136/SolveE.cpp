#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);

int n;
ll k;
ll a[MAX_N];

ll whole = 0LL;

ll ans;

bool check(ll cand) {
  vector<ll> tmp;

  for (int i = 0; i < n; ++i) {
    tmp.push_back(a[i] % cand);
  }

  sort(tmp.begin(), tmp.end());

  vector<ll> plus;
  vector<ll> minus;

  for (auto &e : tmp) {
    if (e == 0) continue;
    plus.push_back(cand - e);
    minus.push_back(e);
  }

  int size = plus.size();

  for (int i = 1; i < size; ++i) {
    plus[i] += plus[i - 1];
    minus[i] += minus[i - 1];
  }

  for (int i = 0; i < size; ++i) {
    if (minus[i] == (plus[size - 1] - plus[i])) {
      if (minus[i] <= k) {
        return true;
      }
    }
  }

  return false;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
    whole += a[i];
  }

  ans = 1LL;

  for (ll i = 1LL; i * i <= whole; ++i) {
    if (whole % i != 0) continue;  // not candidate

    ll other = whole / i;

    if (check(i)) {
      ans = max(ans, i);
    }

    if (check(other)) {
      ans = max(ans, other);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
