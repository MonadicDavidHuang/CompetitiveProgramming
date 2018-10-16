#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int main(void) {
  // Here your code !

  scanf("%d", &n);

  int line_sum = (1 + 9) * 9 / 2;
  int whole = line_sum * line_sum;

  int target = whole - n;

  for (int i = 1; i <= target; ++i) {
    if (target % i != 0) continue;
    int co_i = target / i;

    if (1 <= i && i <= 9 && 1 <= co_i && co_i <= 9) {
      printf("%d x %d\n", i, co_i);
    }
  }

  return 0;
}
