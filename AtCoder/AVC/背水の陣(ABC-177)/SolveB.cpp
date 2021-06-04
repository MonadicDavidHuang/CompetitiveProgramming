#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s, t;

int check(int ps) {
  int ret = 0;

  for (int pt = 0; pt < t.size(); ++pt) {
    if (s[ps + pt] != t[pt]) ret += 1;
  }

  return ret;
}

int main(void) {
  // Here your code !
  cin >> s;
  cin >> t;

  int ans = MAX;

  for (int ps = 0; ps <= s.size() - t.size(); ++ps) {
    ans = min(ans, check(ps));
  }

  printf("%d\n", ans);

  return 0;
}
