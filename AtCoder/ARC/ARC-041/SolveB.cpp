#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e2 + 5);
const int MAX_M = (int)(5e2 + 5);

int n, m;
char cb[MAX_N][MAX_M];

int b[MAX_N][MAX_M];

int a[MAX_N][MAX_M];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%s", &(cb[i]));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      b[i][j] = (int)(cb[i][j] - '0');
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      int min_elem = 10;

      for (int k = 0; k < 4; ++k) {
        min_elem = min(min_elem, b[i + dx[k]][j + dy[k]]);
      }

      a[i][j] = min_elem;

      for (int k = 0; k < 4; ++k) {
        b[i + dx[k]][j + dy[k]] -= min_elem;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
