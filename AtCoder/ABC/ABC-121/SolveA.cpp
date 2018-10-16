#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int h, w, sh, sw;

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  scanf("%d %d", &sh, &sw);

  printf("%d\n", (h - sh) * (w - sw));

  return 0;
}
