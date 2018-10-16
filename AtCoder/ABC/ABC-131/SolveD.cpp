#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;

vector<pair<ll, ll>> bas;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    bas.push_back(make_pair(b, a));
  }

  sort(bas.begin(), bas.end());

  ll cur = 0LL;

  for (auto ba : bas) {
    cur += ba.second;  // plus a

    if (cur > ba.first) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
