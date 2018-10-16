#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

int ans;

/////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  ans = gcd(a[0], a[1]);

  for (int i = 2; i < n; ++i) {
    ans = gcd(a[i], ans);
  }

  printf("%lld\n", ans);

  return 0;
}
