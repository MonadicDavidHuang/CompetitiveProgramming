#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int w, h;

int main(void) {
  // Here your code !
  scanf("%d %d", &w, &h);

  if (3 * w == 4 * h) {
    printf("4:3\n");
  } else {
    printf("16:9\n");
  }

  return 0;
}
