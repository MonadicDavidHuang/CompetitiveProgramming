#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_BIT = (int)(5e3 + 5);

int n, m;

vector<ll> as;
vector<int> cs;

ll memo[MAX_BIT];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    ll a;
    int b;
    scanf("%lld %d", &a, &b);
    as.push_back(a);

    int empty_bit = 0;
    cs.push_back(empty_bit);

    for (int j = 0; j < b; ++j) {
      int c;
      scanf("%d", &c);

      cs.back() |= (1 << (c - 1));
    }
  }

  for (int i = 0; i < MAX_BIT; ++i) {
    memo[i] = INF;
  }

  int empty_bit = 0;
  memo[empty_bit] = 0L;

  for (int b = 0; b < (1 << n); ++b) {
    if (memo[b] == INF) continue;

    for (int i = 0; i < cs.size(); ++i) {
      int new_bit = b;

      new_bit |= cs[i];

      memo[new_bit] = min(memo[new_bit], memo[b] + as[i]);
    }
  }

  int key = 0;
  for (int i = 0; i < n; ++i) {
    key |= (1 << i);
  }

  if (memo[key] == INF) {
    printf("%lld\n", -1L);
  } else {
    printf("%lld\n", memo[key]);
  }

  return 0;
}
