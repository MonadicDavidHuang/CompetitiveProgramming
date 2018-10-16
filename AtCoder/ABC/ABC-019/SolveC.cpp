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

int n;
set<ll> cand;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  ll max_elem = -1;

  for (int i = 0; i < n; ++i) {
    ll tmp;
    scanf("%lld", &tmp);

    cand.insert(tmp);
    max_elem = max(max_elem, tmp);
  }

  set<ll> waste_cand(cand);

  ans = n;

  for (auto e : cand) {
    for (int i = 1; i <= 50; ++i) {
      ll target = e * mypow(2, i);
      if (target > max_elem) break;

      auto itr = waste_cand.find(target);
      if (itr != waste_cand.end()) {
        waste_cand.erase(itr);
      }
    }
  }

  ans = waste_cand.size();

  printf("%d\n", ans);

  return 0;
}
