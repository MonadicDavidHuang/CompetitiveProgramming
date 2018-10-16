#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int a[MAX_N];

ll ans;

ll calc() {
  ll tmp = 0;

  for (int i = 0; i < 5; ++i) {
    tmp += a[i];
    if (i == 4) break;
    while (tmp % 10 != 0) {
      tmp += 1;
    }
  }

  return tmp;
}

int main(void) {
  // Here your code !

  for (int i = 0; i < 5; ++i) {
    scanf("%d", &(a[i]));
  }

  ans = INF;

  do {
    ans = min(ans, calc());
  } while (next_permutation(a, a + 5));

  printf("%lld\n", ans);

  return 0;
}
