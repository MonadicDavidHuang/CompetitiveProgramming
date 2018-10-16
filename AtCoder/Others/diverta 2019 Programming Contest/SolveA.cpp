#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
int k;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  printf("%d\n", n - k + 1);

  return 0;
}
