#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
// 0-indexed
ll digit_bit_count(int digit, ll t) {
  t += 1LL;
  ll window = 1LL << (digit + 1);

  ll div = t / window;
  ll mod = t % window;

  ll ret = 0LL;

  ret += div * window / 2;

  if (mod * 2 > window) {
    ret += mod - (window / 2);
  }

  return ret;
}
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  printf("%lld\n", digit_bit_count(10, 1145141919));

  return 0;
}
