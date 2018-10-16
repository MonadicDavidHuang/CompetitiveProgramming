#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int d[MAX_N];

int ans;

bool check(int k) {
  int top = (int)(lower_bound(d, d + n, k) - d);

  // printf("%d: %d\n", top, k);
  return (top == n - top);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(d[i]));
  }

  sort(d, d + n);

  // for (int i = 0; i < n; ++i) {
  //   printf("%d ", d[i]);

  // }
  // printf("\n");

  int max_d = d[n - 1];

  ans = 0;

  for (int i = 1; i <= max_d; ++i) {
    int k = i;

    if (check(k)) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
