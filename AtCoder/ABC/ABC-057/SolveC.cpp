#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

int ans;

int main(void) {
  // Here your code !
  scanf("%lld\n", &n);

  ans = 10 + 5;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    ll co = n / i;
    int tmp = max(to_string(i).size(), to_string(co).size());
    ans = min(ans, tmp);
  }

  printf("%d\n", ans);

  return 0;
}
