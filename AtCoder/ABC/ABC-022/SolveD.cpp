#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int ax[MAX_N], ay[MAX_N];
int bx[MAX_N], by[MAX_N];

double ans;

double calc_center(int *arr, int n) {
  double center = 0.0;
  for (int i = 0; i < n; ++i) {
    center += arr[i];
  }
  return center /= (double)(n);
}

double calc_length(double cx, double cy, double x, double y) {
  double x_diff = cx - x;
  double y_diff = cy - y;

  return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(ax[i]), &(ay[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(bx[i]), &(by[i]));
  }

  double ax_center = calc_center(ax, n);

  double ay_center = calc_center(ay, n);

  double bx_center = calc_center(bx, n);

  double by_center = calc_center(by, n);

  double a_max_length = -1.0;
  for (int i = 0; i < n; ++i) {
    double cur_length = calc_length(ax_center, ay_center, ax[i], ay[i]);
    a_max_length = max(a_max_length, cur_length);
  }

  double b_max_length = -1.0;
  for (int i = 0; i < n; ++i) {
    double cur_length = calc_length(bx_center, by_center, bx[i], by[i]);
    b_max_length = max(b_max_length, cur_length);
  }

  double p = b_max_length / a_max_length;

  ans = p;

  printf("%.10lf\n", p);

  return 0;
}
