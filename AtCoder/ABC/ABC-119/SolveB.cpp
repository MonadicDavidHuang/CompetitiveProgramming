#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

double ans = 0;

int main(void) {
  // Here your code !

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    double x;
    string u;

    scanf("%lf", &x);
    cin >> u;

    if (u == "BTC") {
      ans += x * 380000.0;
    } else {
      ans += x;
    }
  }

  printf("%lf\n", ans);

  return 0;
}
