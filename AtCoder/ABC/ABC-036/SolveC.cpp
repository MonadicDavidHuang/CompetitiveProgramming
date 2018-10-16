#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
vector<ll> as_origin;
vector<ll> as;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    ll a;
    scanf("%lld", &a);
    as_origin.push_back(a);
    as.push_back(a);
  }

  sort(as.begin(), as.end());
  as.erase(unique(as.begin(), as.end()), as.end());

  unordered_map<ll, int> mp;

  for (int i = 0; i < as.size(); ++i) {
    mp[as[i]] = i;
  }

  for (auto &e : as_origin) {
    printf("%d\n", mp[e]);
  }

  return 0;
}
