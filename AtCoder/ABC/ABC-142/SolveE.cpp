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

  priority_queue<pair<ll, int>> pq;

  int empty_bit = 0;
  pq.push(make_pair(0L, empty_bit));
  memo[empty_bit] = 0L;

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    for (int i = 0; i < cs.size(); ++i) {
      int new_bit = cur.second;

      new_bit |= cs[i];

      if (memo[new_bit] > cur.first + as[i]) {
        memo[new_bit] = cur.first + as[i];
        pq.push(make_pair(memo[new_bit], new_bit));
      }
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
