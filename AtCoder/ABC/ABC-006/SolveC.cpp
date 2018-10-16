#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i <= n; ++i) {
    int x = i;
    int z = (m - 3 * n) + x;
    int y = n - z - x;

    if (x >= 0 && y >= 0 && z >= 0) {
      printf("%d %d %d\n", x, y, z);
      return 0;
    }
  }

  for (int i = 0; i <= n; ++i) {
    int z = i;
    int x = z - (m - 3 * n);
    int y = n - z - x;

    if (x >= 0 && y >= 0 && z >= 0) {
      printf("%d %d %d\n", x, y, z);
      return 0;
    }
  }

  for (int i = 0; i <= n; ++i) {
    int y = i;

    if ((m - 2 * n - y) % 2 != 0) continue;

    int z = (m - 2 * n - y) / 2;
    int x = n - y - z;

    if (x >= 0 && y >= 0 && z >= 0) {
      printf("%d %d %d\n", x, y, z);
      return 0;
    }
  }

  printf("%d %d %d\n", -1, -1, -1);

  return 0;
}
