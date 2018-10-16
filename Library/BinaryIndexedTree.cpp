#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
// (0, n]
class BinaryIndexedTree {
 public:
  vector<ll> arr;
  int n;

  BinaryIndexedTree(int n) {
    this->arr = vector<ll>(n + 1, 0LL);
    this->n = n;
    init();
  }

  void init() {
    for (int i = 0; i < n; ++i) arr[i] = 0LL;
  }

  ll sum(int i) {
    ll s = 0LL;
    while (i > 0) {
      s += arr[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, ll x) {
    while (i <= n) {
      arr[i] += x;
      i += i & -i;
    }
  }
};
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  int n = 1000;

  BinaryIndexedTree bit(n);

  bit.add(1, 1LL);
  bit.add(10, 1LL);
  bit.add(15, 1LL);
  bit.add(17, -1LL);

  for (int i = 1; i <= 20; ++i) {
    printf("%d: %lld\n", i, bit.sum(i));
  }

  return 0;
}
