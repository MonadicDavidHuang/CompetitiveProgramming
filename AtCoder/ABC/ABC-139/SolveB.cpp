#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b;

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &b);

  if (b == 1) {
    printf("%d\n", 0);
    return 0;
  }

  int ans = (b - 1 - 1) / (a - 1) + 1;

  printf("%d\n", ans);

  return 0;
}
