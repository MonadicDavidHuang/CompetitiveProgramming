#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int ans = 0;

int main(void) {
  // Here your code !
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
      bool flg = false;

      for (int l = i; l <= j; ++l) {
        if (s[l] != 'A' && s[l] != 'C' && s[l] != 'G' && s[l] != 'T') {
          flg = true;
          break;
        }
      }

      if (flg) break;

      ans = max(ans, j - i + 1);
    }
  }

  printf("%d\n", ans);

  return 0;
}
