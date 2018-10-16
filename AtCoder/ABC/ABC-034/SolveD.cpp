#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, k;
ll w[MAX_N];
double p[MAX_N];

bool check(double percentage) {
  vector<double> remain;
  for (int i = 0; i < n; ++i) {
    double base = w[i] * p[i] / 100;
    double target = w[i] * percentage / 100;
    remain.push_back(base - target);
  }

  sort(remain.begin(), remain.end(), greater<double>());

  double sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += remain[i];
  }

  return (sum >= 0) ? true : false;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lf\n", &(w[i]), &(p[i]));
  }

  double l = 0;
  double r = 200;

  for (int i = 0; i < 200; ++i) {
    double m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }

  printf("%lf\n", l);

  return 0;
}
