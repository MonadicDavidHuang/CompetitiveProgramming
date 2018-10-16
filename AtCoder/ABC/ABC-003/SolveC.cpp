#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n, k;
int r[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(r[i]));
  }

  sort(r, r + n);

  double c = 0.0;

  for (int i = n - k; i < n; ++i) {
    c = (c + (double)(r[i])) / 2.0;
  }

  printf("%10lf\n", c);

  return 0;
}
