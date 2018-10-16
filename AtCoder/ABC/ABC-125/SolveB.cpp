#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e1 + 5);

int n;
int v[MAX_N];
int c[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(v[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(c[i]));
  }

  ans = -1;

  for (int i = 0; i < 1 << n; ++i) {
    int cv = 0;
    int cc = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        cv += v[j];
        cc += c[j];
      }
    }
    ans = max(ans, cv - cc);
  }

  printf("%d\n", ans);

  return 0;
}
