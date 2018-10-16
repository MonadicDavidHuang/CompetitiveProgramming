#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b;

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &b);

  if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
    printf("%d\n", a * b);
  } else {
    printf("%d\n", -1);
  }

  return 0;
}
