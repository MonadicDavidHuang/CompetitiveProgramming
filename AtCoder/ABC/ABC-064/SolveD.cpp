#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
string s;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  cin >> s;

  int cnt = 0;
  int min_left = 100 + 5;

  for (int i = 0; i < s.size(); ++i) {
    cnt += (s[i] == '(') ? 1 : -1;
    min_left = min(min_left, cnt);
  }

  if (min_left < 0) {
    for (int i = 0; i < (-1) * min_left; ++i) {
      s.insert(0, "(");
    }
  }

  cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    cnt += (s[i] == '(') ? 1 : -1;
  }

  for (int i = 0; i < cnt; ++i) {
    s.push_back(')');
  }

  cout << s << endl;

  return 0;
}
