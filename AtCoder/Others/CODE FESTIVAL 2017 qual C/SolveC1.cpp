#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !

  cin >> s;

  int l = 0;
  int r = s.size() - 1;

  int ans = 0;

  while (l <= r) {
    if (s[l] == s[r]) {
      l += 1;
      r -= 1;
    } else if (s[l] == 'x') {  // append 'x' on tail
      l += 1;
      ans += 1;
    } else if (s[r] == 'x') {  // append 'x' on head
      r -= 1;
      ans += 1;
    } else {
      printf("%d\n", -1);
      return 0;
    }
  }

  printf("%d\n", ans);

  return 0;
}
