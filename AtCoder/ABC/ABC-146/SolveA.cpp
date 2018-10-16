#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  int ans;

  if (s == "SUN")
    ans = 7;
  else if (s == "MON")
    ans = 6;
  else if (s == "TUE")
    ans = 5;
  else if (s == "WED")
    ans = 4;
  else if (s == "THU")
    ans = 3;
  else if (s == "FRI")
    ans = 2;
  else if (s == "SAT")
    ans = 1;

  cout << ans << endl;

  return 0;
}
