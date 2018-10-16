#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, d;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &d);

  printf("%d", (n - 1 + 2 * d + 1) / (2 * d + 1));

  return 0;
}
