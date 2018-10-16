#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);
const int MAX_X = (int)(1e4 + 5);

double acc[MAX_X];

int n, q;

double calc_vol(double x, double r, double h, double di) {
  double length = x + h - di;

  double rp = length * (r / h);

  double base = M_PI * rp * rp;

  double vol = base * length / 3.0;

  return vol;
}

void add(double x, double r, double h) {
  for (int i = 1; i < MAX_X; ++i) {
    double di = (double)(i);
    if (di <= x || (x + h) < di) {
      continue;
    }

    double commit = calc_vol(x, r, h, di - 1.0) - calc_vol(x, r, h, di);

    acc[i] += commit;
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    double x, r, h;
    scanf("%lf %lf %lf", &x, &r, &h);
    add(x, r, h);
  }

  for (int i = 1; i < MAX_X; ++i) {
    acc[i] += acc[i - 1];
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    double ans = acc[b] - acc[a];

    printf("%lf\n", ans);
  }

  return 0;
}
