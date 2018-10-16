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

ll n;

ll ans;

bool check(ll next, ll target) { return (n % next <= target); }

ll search(ll ok, ll ng, ll target) {
  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2;
    if (check(next, target)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  if (n % ok == target) {
    return ok;
  } else {
    return -1LL;
  }
}

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ans = 0;

  for (ll cur_div = 1; cur_div * cur_div <= n + 1; ++cur_div) {
    ll start = n / cur_div;
    ll goal = n / (cur_div + 1);

    ll tmp = search(start, goal, cur_div);
    ans += tmp < 0 ? 0 : tmp;
  }

  printf("%lld\n", ans);

  return 0;
}
