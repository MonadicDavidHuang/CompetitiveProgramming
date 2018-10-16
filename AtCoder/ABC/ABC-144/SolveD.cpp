#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const double eps = (double)(1e-6);

double a, b, x;

double calc_radian(double deg) { return (deg / 360.0) * 2 * M_PI; }

bool should_change(double deg) {
  double target_radian = calc_radian(deg);

  double tanjent_b_over_a = b / a;
  double limit_radian = atanl(tanjent_b_over_a);

  return (limit_radian - eps) <= target_radian;
}

double calc_before_limit(double deg) {
  double c = a * tanl(calc_radian(deg));

  double whole = a * a * b;

  double subtract_part = a * c * 0.5 * a;

  double ret = whole - subtract_part;

  // printf("deg: %lf, body: %lf\n", deg, ret);

  return ret;
}

double calc_after_limit(double deg) {
  double gamma = b * tanl(calc_radian(90.0 - deg));

  double ret = b * gamma * 0.5 * a;

  // printf("deg: %lf, body: %lf\n", deg, ret);

  return ret;
}

bool check(double deg) {
  if (should_change(deg)) {
    // printf("after\n");
    return (x - eps) <= calc_after_limit(deg);
  } else {
    // printf("before\n");
    return (x - eps) <= calc_before_limit(deg);
  }
}

int main(void) {
  // Here your code !
  scanf("%lf %lf %lf", &a, &b, &x);

  // [0.0, 90.0)
  double ok = 0.0;
  double ng = 90.0;

  for (int i = 0; i <= 200; ++i) {
    double next = (ok + ng) / 2.0;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  double ans = ok;

  printf("%lf\n", ans);

  return 0;
}
