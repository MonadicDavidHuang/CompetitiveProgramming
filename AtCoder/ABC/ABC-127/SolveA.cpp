#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b;

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &b);

  if (a >= 13) {
    printf("%d\n", b);
  } else if (6 <= a && a <= 12) {
    printf("%d\n", b / 2);
  } else {
    printf("%d\n", 0);
  }

  return 0;
}
