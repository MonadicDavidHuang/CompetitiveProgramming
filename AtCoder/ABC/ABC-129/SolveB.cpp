#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
ll w[MAX_N];

ll ans = INF;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(w[i]));
  }

  ll whole = 0;

  for (int i = 0; i < n; ++i) {
    whole += w[i];
  }

  ll cur = w[0];

  ans = min(ans, abs(whole - cur - cur));

  for (int i = 1; i < n; ++i) {
    cur += w[i];
    ans = min(ans, abs(whole - cur - cur));
  }

  printf("%lld\n", ans);

  return 0;
}
