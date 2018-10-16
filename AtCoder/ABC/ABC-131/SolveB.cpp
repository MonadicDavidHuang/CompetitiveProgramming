#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, l;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &l);

  ll whole = (0 + n - 1) * n / 2;
  whole += l * n;

  ll cur = INF;
  ans = whole;

  for (int i = 0; i < n; ++i) {
    if (cur > abs(whole - (whole - (i + l)))) {
      ans = whole - (i + l);
      cur = abs(whole - (whole - (i + l)));
    }
  }

  printf("%lld\n", ans);

  return 0;
}
