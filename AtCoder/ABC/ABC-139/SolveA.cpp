#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;
string t;

int main(void) {
  // Here your code !
  cin >> s;
  cin >> t;

  int ans = 0;

  for (int i = 0; i < s.size(); ++i) {
    ans += (s[i] == t[i]) ? 1 : 0;
  }

  printf("%d\n", ans);

  return 0;
}
