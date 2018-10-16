#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n;
ll x;

ll size[MAX_N];

map<pair<int, ll>, ll> memo;

ll ans;

ll calc(int l, ll b) {
  auto key = make_pair(l, b);
  if (memo.find(key) != memo.end()) {
    return memo[key];
  }

  if (l == 0) {
    return 1LL;
  }

  ll child = size[l - 1];

  ll ret;

  if (b <= 1) {
    ret = 0LL;
  } else if (1 < b && b <= 1 + child) {
    ret = calc(l - 1, b - 1);
  } else if (b == 1 + child + 1) {
    ret = calc(l - 1, child) + 1;
  } else if (1 + child + 1 < b && b <= 1 + child + 1 + child) {
    ret = calc(l - 1, child) + 1 + calc(l - 1, b - (1 + child + 1));
  } else if (b == 1 + child + 1 + child + 1) {
    ret = calc(l - 1, child) * 2 + 1;
  }

  return memo[key] = ret;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &x);

  size[0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    size[i] = size[i - 1] * 2 + 3;
  }

  ans = calc(n, x);

  printf("%lld\n", ans);

  return 0;
}
