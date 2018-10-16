#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, a, b;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &a, &b);

  printf("%d\n", min(n * a, b));

  return 0;
}
