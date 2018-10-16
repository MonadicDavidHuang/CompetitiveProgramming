#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const ll MAX = (ll)(1e9 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

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

int n;
ll a[MAX_N];
ll b[MAX_N];

int s[MAX_N];

BinaryIndexedTree bit(MAX_N * 2);

bool check(ll x) {
  ll num = 0;

  for (int i = 1; i <= n; ++i) s[i] = (a[i] >= x) ? 1 : -1;
  for (int i = 1; i <= n; ++i) s[i] += s[i - 1];

  bit.init();

  for (int i = 0; i <= n; ++i) {
    num += bit.sum(s[i] + MAX_N);
    bit.add(s[i] + MAX_N, 1);
  }

  ll whole = (1LL * (n + 1) * n) / 2;
  ll target = (whole - 1) / 2 + 1;

  return (num >= target);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));
    b[i] = a[i];
  }

  sort(b + 1, b + n + 1);

  b[n + 1] = b[n] + 1;  // guard

  int ok = 1;
  int ng = n + 1;

  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (check(b[next])) {
      ok = next;
    } else {
      ng = next;
    }
  }

  printf("%lld\n", b[ok]);

  return 0;
}
