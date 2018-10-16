#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const double EPS = (double)(1e-9);

double a, b, c;

double calc(double t) { return a * t + b * sin(c * t * M_PI); }

bool check(double next) { return 100.0 - EPS <= calc(next); }

int main(void) {
  // Here your code !
  scanf("%lf %lf %lf \n", &a, &b, &c);

  double ok = a * 100.0;
  double ng = 0.0;

  for (int i = 0; i < 200; ++i) {
    double next = (ok + ng) / 2.0;
    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  printf("%.20lf\n", ok);

  return 0;
}
