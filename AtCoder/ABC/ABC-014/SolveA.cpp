#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &a);
  scanf("%d", &b);

  ans = (a % b == 0) ? 0 : b * (a / b + 1) - a;

  printf("%d\n", ans);

  return 0;
}
