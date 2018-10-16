#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

double n, k;

double ans;

int main(void) {
  // Here your code !
  scanf("%lf %lf", &n, &k);

  ll top = 6.0 * (n - k) * (k - 1) + 3.0 * ((n - k) + (k - 1)) + 1.0;

  ans = (top) / (n * n * n);

  printf("%.10lf\n", ans);

  return 0;
}
