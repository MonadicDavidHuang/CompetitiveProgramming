#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b;

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &b);

  printf("%d\n", max(max(a + a - 1, a + b), b + b - 1));

  return 0;
}
