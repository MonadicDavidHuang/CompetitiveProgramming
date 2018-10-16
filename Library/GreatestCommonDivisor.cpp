#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  ll a = 10;
  ll b = 1919810;

  printf("%lld\n", gcd(a, b));

  return 0;
}
