#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(20 + 5);

int n, m, c;
int b[MAX_N];

int ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &m, &c);

  for (int i = 0; i < m; ++i) {
    scanf("%d", &(b[i]));
  }

  for (int i = 0; i < n; ++i) {
    int tmp = 0;
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      tmp += b[j] * a;
    }

    if ((tmp + c) > 0) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
