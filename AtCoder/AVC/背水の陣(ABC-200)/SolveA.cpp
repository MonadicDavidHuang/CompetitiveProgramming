#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  int ans = (n - 1) / 100 + 1;

  printf("%d\n", ans);

  return 0;
}
