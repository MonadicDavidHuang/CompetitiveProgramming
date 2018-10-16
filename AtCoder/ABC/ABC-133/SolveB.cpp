#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);
const int MAX_D = (int)(1e1 + 5);

int n, d;
int x[MAX_N][MAX_D];

int ans;

bool check(int i, int j) {
  int base = 0;
  for (int k = 0; k < d; ++k) {
    base += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
  }

  int tmp = (int)(sqrt(base));

  return (tmp * tmp == base);
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &d);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      scanf("%d", &(x[i][j]));
    }
  }

  ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (check(i, j)) ans += 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
