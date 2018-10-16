#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  int depth = 0;
  for (ll i = n; i > 1; i /= 2) {
    depth += 1;
  }

  ll cur = 1;

  int cnt = 0;
  while (cur <= n) {
    if (cnt % 2 == 0) {
      if (depth % 2 == 1) {
        cur = cur * 2;
      } else {
        cur = cur * 2 + 1;
      }
    } else {
      if (depth % 2 == 1) {
        cur = cur * 2 + 1;
      } else {
        cur = cur * 2;
      }
    }

    cnt += 1;
  }

  if (cnt % 2 == 0)
    printf("Takahashi\n");
  else
    printf("Aoki\n");

  return 0;
}
