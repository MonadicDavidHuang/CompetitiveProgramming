#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int r, d, x;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &r, &d, &x);

  for (int i = 1; i <= 10; ++i) {
    x = r * x - d;

    printf("%d\n", x);
  }

  return 0;
}
