#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int m, d;

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &m, &d);

  ans = 0;

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= d; ++j) {
      int d1 = j / 10;
      int d2 = j % 10;

      if (i == d1 * d2 && d1 >= 2 && d2 >= 2) {
        ans += 1;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
