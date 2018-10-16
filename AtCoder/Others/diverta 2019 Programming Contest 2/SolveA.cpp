#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  if (k == 1) {
    printf("%d\n", 0);

    return 0;
  }

  printf("%d\n", n - (k - 1) - 1);

  return 0;
}
