#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n;
double v[MAX_N];

double ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lf", &(v[i]));
  }

  sort(v, v + n);

  ans = v[0];

  for (int i = 1; i < n; ++i) {
    ans = (ans + v[i]) / 2.0;
  }

  printf("%lf\n", ans);

  return 0;
}
