#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  ans = 0;

  for (int i = 1; i <= n; ++i) {
    string tmp = to_string(i);

    ans += (tmp.size() % 2 == 1) ? 1 : 0;
  }

  printf("%d\n", ans);

  return 0;
}
