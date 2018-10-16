#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, p;

int main(void) {
  // Here your code !
  scanf("%d %d", &a, &p);

  p += a * 3;

  printf("%d\n", p / 2);

  return 0;
}
