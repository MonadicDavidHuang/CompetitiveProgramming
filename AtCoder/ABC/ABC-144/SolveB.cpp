#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= 9; ++i) {
    if (n % i != 0) continue;

    int div = n / i;

    if (1 <= div && div <= 9) {
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");

  return 0;
}
