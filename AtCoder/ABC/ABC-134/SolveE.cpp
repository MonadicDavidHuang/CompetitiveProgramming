#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

multiset<ll> mst;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    auto ptr = mst.upper_bound(a[i] - 1);

    if (mst.empty() || ptr == mst.begin()) {
      mst.insert(a[i]);
      continue;
    }

    auto prv = prev(ptr);
    mst.erase(prv);
    mst.insert(a[i]);
  }

  printf("%d\n", mst.size());

  return 0;
}
