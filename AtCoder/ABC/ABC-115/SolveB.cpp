#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  int sum = 0;

  int maxelem = -1;

  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);

    maxelem = max(maxelem, tmp);
    sum += tmp;
  }

  printf("%d\n", sum - maxelem / 2);

  return 0;
}
