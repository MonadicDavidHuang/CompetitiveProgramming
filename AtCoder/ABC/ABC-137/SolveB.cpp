#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int k, x;

int main(void) {
  // Here your code !
  scanf("%d %d", &k, &x);

  for (int i = -1000000; i <= 1000000; ++i) {
    if (abs(i - x) <= k - 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
