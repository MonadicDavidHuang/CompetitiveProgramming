#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);

int n, m;

int deg[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    deg[a] += 1;
    deg[b] += 1;
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", deg[i]);
  }

  return 0;
}
