#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b, c, d, e, f;

double ans;

int main(void) {
  // Here your code !
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

  int x1 = c - a;
  int y1 = d - b;
  int x2 = e - a;
  int y2 = f - b;

  ans = double(abs(x1 * y2 - x2 * y1)) / 2.0;

  printf("%lf\n", ans);

  return 0;
}
