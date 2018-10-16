#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n, x;
int l[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &x);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(l[i]));
  }

  int last = 0;

  int cnt = (last <= x) ? 1 : 0;

  for (int i = 1; i <= n; ++i) {
    last += l[i - 1];
    cnt += (last <= x) ? 1 : 0;
  }

  ans = cnt;

  printf("%d\n", ans);

  return 0;
}
