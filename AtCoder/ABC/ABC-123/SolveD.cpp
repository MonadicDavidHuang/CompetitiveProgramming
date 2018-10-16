#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using node = tuple<ll, int, int, int>;

const int MAX_X = (int)(1e3 + 5);
const int MAX_Y = (int)(1e3 + 5);
const int MAX_Z = (int)(1e3 + 5);
const int MAX_K = (int)(3e3 + 5);

int x, y, z, k;
ll a[MAX_X], b[MAX_Y], c[MAX_Z];

int main(void) {
  // Here your code !
  scanf("%d %d %d %d", &x, &y, &z, &k);

  for (int i = 0; i < x; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < y; ++i) {
    scanf("%lld", &(b[i]));
  }

  for (int i = 0; i < z; ++i) {
    scanf("%lld", &(c[i]));
  }

  sort(a, a + x, greater<ll>());
  sort(b, b + y, greater<ll>());
  sort(c, c + z, greater<ll>());

  priority_queue<node> pq;
  pq.push(node(a[0] + b[0] + c[0], 0, 0, 0));

  set<node> visited;

  int cnt = 0;
  while (!pq.empty()) {
    node cur = pq.top();
    pq.pop();

    if (visited.find(cur) != visited.end()) continue;

    visited.insert(cur);

    ll cost = get<0>(cur);
    int ia = get<1>(cur);
    int ib = get<2>(cur);
    int ic = get<3>(cur);

    printf("%lld\n", cost);

    cnt += 1;

    if (cnt == k) {
      break;
    }

    if (ia + 1 < x) pq.push(node(cost - a[ia] + a[ia + 1], ia + 1, ib, ic));
    if (ib + 1 < y) pq.push(node(cost - b[ib] + b[ib + 1], ia, ib + 1, ic));
    if (ic + 1 < z) pq.push(node(cost - c[ic] + c[ic + 1], ia, ib, ic + 1));
  }

  return 0;
}
