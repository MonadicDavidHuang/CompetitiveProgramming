#include <bits/stdc++.h>
#include <math.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
double xz, yz, xh, yh;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  scanf("%lf %lf", &xz, &yz);
  scanf("%lf %lf", &xh, &yh);

  double mid_x = (xz + xh) / 2.0;
  double mid_y = (yz + yh) / 2.0;

  double vec_xz = xz - mid_x;
  double vec_yz = yz - mid_y;

  double phi = 180.0 - (double(n) - 2.0) * 180.0 / double(n);

  double vec_x1 = vec_xz * cos(phi * M_PI / 180.0) - vec_yz * sin(phi * M_PI / 180.0);
  double vec_y1 = vec_xz * sin(phi * M_PI / 180.0) + vec_yz * cos(phi * M_PI / 180.0);

  double x1 = mid_x + vec_x1;
  double y1 = mid_y + vec_y1;

  printf("%lf %lf\n", x1, y1);

  return 0;
}
