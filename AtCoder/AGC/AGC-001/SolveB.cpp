#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n, x;

ll ans;

ll calc(ll cur_x, ll cur_length) {
  ll part = cur_length / cur_x;
  if (cur_length % cur_x == 0) {  // just returned start point
    return (part * 2 - 1) * cur_x;
  } else {  // did not return, spray more detailed ray
    ll next_x = cur_length % cur_x;
    ll next_length = cur_x;
    return (part * 2) * cur_x + calc(next_x, next_length);
  }
}

int main(void) {
  // Here your code !
  scanf("%lld %lld\n", &n, &x);

  if (n % 2 == 0 && x == (n / 2)) {
    ans = 3 * x;
  } else {
    ll cur_x = x;
    ll cur_length = n - x;
    ans = cur_x + cur_length + calc(cur_x, cur_length);
  }

  printf("%lld\n", ans);

  return 0;
}
