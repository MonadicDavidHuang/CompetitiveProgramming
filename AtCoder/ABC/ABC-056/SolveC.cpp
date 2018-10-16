#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int x;

int main(void) {
  // Here your code !
  scanf("%lld", &x);

  ll acc = 0;

  int i = 0;
  while (true) {
    acc += i;
    if (acc >= x) break;
    i += 1;
  }

  printf("%d\n", i);

  return 0;
}
