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

  double phi = double((n - 2) * 180.0 / (n * 2));
  double cosign_phi = cos(phi * M_PI / 180.0);

  double vec_a_x = xh - xz;
  double vec_a_y = yh - yz;

  double a_length = sqrt(pow(vec_a_x, 2) + pow(vec_a_y, 2));

  double b_length = cosign_phi * a_length;

  double vec_a_x_shrink = vec_a_x * (b_length / a_length);
  double vec_a_y_shrink = vec_a_y * (b_length / a_length);

  double rev_phi = 360.0 - phi;

  double vec_a_x_shrink_rot = vec_a_x_shrink * cos(rev_phi * M_PI / 180.0) - vec_a_y_shrink * sin(rev_phi * M_PI / 180.0);
  double vec_a_y_shrink_rot = vec_a_x_shrink * sin(rev_phi * M_PI / 180.0) + vec_a_y_shrink * cos(rev_phi * M_PI / 180.0);

  double x1 = xz + vec_a_x_shrink_rot;
  double y1 = yz + vec_a_y_shrink_rot;

  printf("%lf %lf\n", x1, y1);

  return 0;
}
