#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int x, y;

int main(void) {
  // Here your code !
  scanf("%d %d", &x, &y);

  if (x < y) {
    printf("Better\n");
  } else {
    printf("Worse");
  }

  return 0;
}
