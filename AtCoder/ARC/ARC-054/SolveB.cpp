#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

double p;

double ans;

double calc(double x) { return x + p / pow(2.0, x / 1.5); }

int main(void) {
  // Here your code !
  scanf("%lf", &p);

  if (p == 0.0) {
    printf("%lf\n", p);
    return 0;
  }

  double left = 0.0;
  double right = 1.0e18;

  for (int i = 0; i < 200; ++i) {
    double tmp_left = (left + left + right) / 3.0;
    double tmp_right = (left + right + right) / 3.0;

    if (calc(tmp_left) > calc(tmp_right)) {
      left = tmp_left;
    } else {
      right = tmp_right;
    }
  }

  ans = calc((left + right) / 2.0);

  printf("%.12lf\n", ans);

  return 0;
}
