#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;
priority_queue<ll> pq;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    ll a;
    scanf("%lld", &a);
    pq.push(a);
  }

  for (int i = 0; i < m; ++i) {
    ll cur = pq.top();
    pq.pop();

    pq.push(cur / 2);
  }

  ll ans = 0;

  while (!pq.empty()) {
    ll cur = pq.top();
    pq.pop();
    ans += cur;
  }

  printf("%lld\n", ans);

  return 0;
}
