#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll m;

vector<pair<ll, ll>> pairs;

ll ans = 0;

int main(void) {
  // Here your code !

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    pairs.push_back(make_pair(a, b));
  }

  sort(pairs.begin(), pairs.end());

  ll bought = 0;

  for (auto e : pairs) {
    if (bought < m) {
      ans += e.first * min(e.second, m - bought);
      bought += min(e.second, m - bought);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
