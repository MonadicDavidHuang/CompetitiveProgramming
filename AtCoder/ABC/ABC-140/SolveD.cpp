#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;
string s;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  cin >> s;

  int cnt = 0;
  int diff = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1])
      diff += 1;
    else
      cnt += 1;
  }

  int ans = cnt + min(2 * k, diff);

  printf("%d\n", ans);

  return 0;
}
