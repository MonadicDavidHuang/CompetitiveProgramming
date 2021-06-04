#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
string cs;

int main(void) {
  // Here your code !

  scanf("%d", &n);

  cin >> cs;

  int l = 0, r = n - 1;

  int ans = 0;

  while (l < r) {
    while (cs[l] == 'R') l += 1;
    while (cs[r] == 'W') r -= 1;

    if (l < r) {
      cs[l] = 'R';
      cs[r] = 'W';

      ans += 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
