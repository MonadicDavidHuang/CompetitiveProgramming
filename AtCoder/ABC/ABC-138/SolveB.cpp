#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
double a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lf", &(a[i]));
  }

  double cnt = 0.0;

  for (int i = 0; i < n; ++i) {
    cnt += 1.0 / a[i];
  }

  double ans = 1.0 / cnt;

  printf("%lf\n", ans);

  return 0;
}
