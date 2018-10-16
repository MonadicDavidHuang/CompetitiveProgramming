#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

string r_s;

int main(void) {
  // Here your code !
  cin >> s;

  int n = s.size();

  s.push_back('B');

  int i = 0;
  while (i < n - 1) {
    if (s[i] == 'B' && s[i + 1] == 'C') {
      r_s.push_back('D');
      i += 2;
    } else {
      r_s.push_back(s[i]);
      i += 1;
    }
  }

  ll cur_a = 0;
  ll cnt = 0;

  for (auto e : r_s) {
    if (e == 'A') {
      cur_a += 1;
    } else if (e == 'D') {
      cnt += cur_a;
    } else {
      cur_a = 0;
    }
  }

  printf("%lld\n", cnt);

  return 0;
}
