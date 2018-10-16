#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);
const int MAX_M = (int)(5e1 + 5);

int n, m;

char a[MAX_N][MAX_M];
char b[MAX_N][MAX_M];

bool check(int i, int j) {
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < m; ++y) {
      if (a[i + x][j + y] != b[x][y]) {
        return false;
      }
    }
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%s", &(a[i]));
  }

  for (int i = 0; i < m; ++i) {
    scanf("%s", &(b[i]));
  }

  for (int i = 0; i <= n - m; ++i) {
    for (int j = 0; j <= n - m; ++j) {
      if (check(i, j)) {
        printf("Yes\n");
        return 0;
      }
    }
  }

  printf("No\n");

  return 0;
}
