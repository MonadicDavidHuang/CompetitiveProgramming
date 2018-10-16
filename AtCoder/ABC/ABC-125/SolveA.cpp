#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b, t;

int ans;

int main(void) {
  // Here your code !

  scanf("%d %d %d", &a, &b, &t);

  ans = (t / a) * b;

  printf("%d\n", ans);

  return 0;
}
