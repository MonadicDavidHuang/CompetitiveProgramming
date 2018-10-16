#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s = "Sunny", c = "Cloudy", r = "Rainy";

string w;

int main(void) {
  // Here your code !
  cin >> w;

  string ans;

  if (w == s) {
    ans = c;
  } else if (w == c) {
    ans = r;
  } else {
    ans = s;
  }

  cout << ans << endl;

  return 0;
}
