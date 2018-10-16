#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(8 + 5);

int n;
double x[MAX_N];
double y[MAX_N];

double calc(double last_x, double last_y, double cur_x, double cur_y) {
  double first = (cur_x - last_x) * (cur_x - last_x);
  double second = (cur_y - last_y) * (cur_y - last_y);
  return sqrt(first + second);
}

double path(vector<int>& v) {
  double ret = 0.0;

  double last_x = x[v[0]];
  double last_y = y[v[0]];

  for (int i = 1; i < v.size(); ++i) {
    double cur_x = x[v[i]];
    double cur_y = y[v[i]];

    ret += calc(last_x, last_y, cur_x, cur_y);
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lf %lf", &(x[i]), &(y[i]));
  }

  vector<int> v;

  for (int i = 0; i < n; ++i) {
    v.push_back(i);
  }

  double whole = 0.0;

  do {
    whole += path(v);
  } while (next_permutation(v.begin(), v.end()));

  double under = 1.0;

  for (int i = 1; i <= n; ++i) {
    under *= (double)(i);
  }

  double ans = whole / under;

  printf("%lf\n", ans);

  return 0;
}
