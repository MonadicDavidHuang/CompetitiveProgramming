#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int ans;

int main(void) {
  // Here your code !
  cin >> s;

  int cnt0 = 0;
  // 0 start
  for (int i = 0; i < s.size(); ++i) {
    char cur = (i % 2 == 0) ? '0' : '1';
    if (cur != s[i]) cnt0 += 1;
  }

  int cnt1 = 0;
  // 1 start
  for (int i = 0; i < s.size(); ++i) {
    char cur = (i % 2 == 0) ? '1' : '0';
    if (cur != s[i]) cnt1 += 1;
  }

  ans = min(cnt0, cnt1);

  printf("%d\n", ans);

  return 0;
}
