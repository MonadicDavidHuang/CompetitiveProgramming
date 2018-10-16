#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
int a[MAX_N];

int frd[MAX_N];
int brd[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }

  frd[0] = a[0];
  for (int i = 1; i < n; ++i) {
    frd[i] = max(a[i], frd[i - 1]);
  }

  brd[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    brd[i] = max(brd[i + 1], a[i]);
  }

  printf("%d\n", brd[1]);

  for (int i = 1; i < n - 1; ++i) {
    int ans = max(frd[i - 1], brd[i + 1]);

    printf("%d\n", ans);
  }

  printf("%d\n", frd[n - 2]);

  return 0;
}
