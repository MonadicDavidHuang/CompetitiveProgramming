#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);
const double EPS = (double)(1e-9);

int n;
double x[MAX_N];
double y[MAX_N];

vector<double> calc_radians(int center) {
  vector<double> radians;

  double cx = x[center];
  double cy = y[center];

  for (int i = 1; i <= n; ++i) {
    if (i == center) continue;

    double cur_radian = atan2(y[i] - cy, x[i] - cx);
    radians.push_back(cur_radian);
  }

  sort(radians.begin(), radians.end());

  vector<double> ret;

  for (auto radian : radians) {
    ret.push_back(radian);
  }

  for (auto radian : radians) {
    ret.push_back(radian + 2.0 * M_PI);
  }

  return ret;
}

// return pair of number of (rad == pi / 2, rad < pi)
pair<ll, ll> count_triangle(vector<double> radians) {
  double half_pi = M_PI / 2.0;

  ll just_half_pi = 0;
  ll less_pi_above_half_pi = 0;

  for (int i = 0; i < n - 1; ++i) {
    // case: rad == pi / 2
    int l_h = lower_bound(radians.begin() + i, radians.end(),
                          radians[i] + half_pi - EPS) -
              radians.begin();
    int u_h = upper_bound(radians.begin() + i, radians.end(),
                          radians[i] + half_pi + EPS) -
              radians.begin();
    just_half_pi += u_h - l_h;

    // case: rad < pi
    int l = lower_bound(radians.begin() + i, radians.end(),
                        radians[i] + M_PI - EPS) -
            radians.begin();
    less_pi_above_half_pi += l - u_h;
  }

  return make_pair(just_half_pi, less_pi_above_half_pi);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf", &(x[i]), &(y[i]));
  }

  ll just_half_pi = 0;
  ll less_pi_above_half_pi = 0;

  for (int i = 1; i <= n; ++i) {
    auto radians = calc_radians(i);

    auto cur_pair = count_triangle(radians);

    just_half_pi += cur_pair.first;
    less_pi_above_half_pi += cur_pair.second;
  }

  ll ln = (ll)(n);

  ll less_half_pi =
      (ln * (ln - 1) * (ln - 2)) / 6 - (just_half_pi + less_pi_above_half_pi);

  printf("%d %d %d\n", less_half_pi, just_half_pi, less_pi_above_half_pi);

  return 0;
}
