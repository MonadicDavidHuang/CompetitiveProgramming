#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int x, y;

int main(void) {
  // Here your code !
  scanf("%d %d", &x, &y);

  int ans = 0;

  if (x == 1 && y == 1) ans += 400000;

  if (x == 1)
    ans += 300000;
  else if (x == 2)
    ans += 200000;
  else if (x == 3)
    ans += 100000;

  if (y == 1)
    ans += 300000;
  else if (y == 2)
    ans += 200000;
  else if (y == 3)
    ans += 100000;

  printf("%d\n", ans);

  return 0;
}
