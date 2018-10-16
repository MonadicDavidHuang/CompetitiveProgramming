#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

ll ans = 0;

int main(void) {
  // Here your code !
  cin >> s;

  for (int i = 0; i < 1 << s.size() - 1; ++i) {
    ll tmpsum = 0;
    string tmpstr = "";
    for (int j = 0; j < s.size() - 1; ++j) {
      tmpstr += s[j];
      if (i >> j & 1) {
        tmpsum += stoll(tmpstr);
        tmpstr = "";
      }
    }
    tmpstr += s.back();
    tmpsum += stoll(tmpstr);
    ans += tmpsum;
  }

  printf("%lld\n", ans);

  return 0;
}
