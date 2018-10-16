#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

ll n, d;
ll x, y;

double prob[MAX_N][MAX_N];

double ans;

void prepare(int n) {
  prob[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      prob[i][j] = (prob[i - 1][j - 1] + prob[i - 1][j]) / 2.0;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &d);
  scanf("%lld %lld", &x, &y);

  if (!(x % d == 0 && y % d == 0)) {
    printf("%.2lf\n", 0.0);
    return 0;
  }

  ll x_times = abs(x) / d;
  ll y_times = abs(y) / d;

  prepare(n + 3);

  for (int i = 0; i <= n; ++i) {
    int x_use = i;
    int y_use = n - i;

    if (x_use < x_times || y_use < y_times) continue;
    if ((x_use + x_times) % 2 != 0 || (y_use + y_times) % 2 != 0) continue;

    double cur_prob = 1.0;
    cur_prob *= prob[n][x_use];
    cur_prob *= prob[x_use][(x_use + x_times) / 2];
    cur_prob *= prob[y_use][(y_use + y_times) / 2];

    ans += cur_prob;
  }

  printf("%.10lf\n", ans);

  return 0;
}
