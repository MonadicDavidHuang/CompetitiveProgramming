#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;

ll field[MAX_M];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  ll whole = 0LL;

  for (int i = 0; i < n; ++i) {
    int l, r;
    ll s;
    scanf("%d %d %lld", &l, &r, &s);

    whole += s;

    field[l] += s;
    field[r + 1] += -s;
  }

  for (int i = 0; i < MAX_M - 1; ++i) {
    field[i + 1] += field[i];
  }

  ll min_elem = INF;

  for (int i = 1; i <= m; ++i) {
    min_elem = min(min_elem, field[i]);
  }

  printf("%lld\n", whole - min_elem);

  return 0;
}
