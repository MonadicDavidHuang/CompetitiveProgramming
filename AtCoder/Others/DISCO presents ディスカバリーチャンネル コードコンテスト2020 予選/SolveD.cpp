#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_M = (int)(2e5 + 5);

int m;

ll d[MAX_M];
ll c[MAX_M];

int main(void) {
  // Here your code !
  scanf("%d", &m);

  for (int i = 0; i < m; ++i) {
    scanf("%lld %lld", &(d[i]), &(c[i]));
  }

  ll whole = 0LL;
  for (int i = 0; i < m; ++i) {
    whole += d[i] * c[i];
  }

  ll digit = 0LL;
  for (int i = 0; i < m; ++i) {
    digit += c[i];
  }

  ll ans = (digit - 1LL) + (whole / 9LL);

  if (whole % 9LL == 0LL) {
    ans -= 1LL;
  }

  printf("%lld\n", ans);

  return 0;
}
