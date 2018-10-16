#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e6 + 5);

int n;

int acc[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    acc[a] += 1;
    acc[b + 1] -= 1;
  }

  for (int i = 1; i < MAX_N; ++i) {
    acc[i] += acc[i - 1];
  }

  ans = -1;

  for (int i = 0; i < MAX_N; ++i) {
    ans = max(ans, acc[i]);
  }

  printf("%d\n", ans);

  return 0;
}
