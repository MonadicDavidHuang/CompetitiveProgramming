#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int t, a;

int ans;

int main(void) {
  // Here your code !

  scanf("%d", &n);
  scanf("%d %d", &t, &a);

  int ho;
  scanf("%d", &ho);

  double cur = t - ho * 0.006;

  double tmp = abs(cur - a);
  ans = 1;

  for (int i = 2; i <= n; ++i) {
    int h;
    scanf("%d", &h);

    double cur = t - h * 0.006;

    if (abs(cur - a) < tmp) {
      tmp = abs(cur - a);
      ans = i;
    }
  }

  printf("%d\n", ans);

  return 0;
}
