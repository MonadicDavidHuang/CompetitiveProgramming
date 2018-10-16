#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

int h[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(h[i]));
  }

  ans = 1;

  for (int i = 1; i < n; ++i) {
    bool flg = true;
    for (int j = 0; j < i; ++j) {
      if (h[j] > h[i]) {
        flg = false;
        break;
      }
    }
    if (flg) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
