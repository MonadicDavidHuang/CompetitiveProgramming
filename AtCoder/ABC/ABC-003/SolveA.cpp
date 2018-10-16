#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

double ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  ans = ((n + 1) * n * 1e4) / (2 * n);

  printf("%lf\n", ans);

  return 0;
}
