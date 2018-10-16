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

  int zero = 0;
  int one = 0;

  for (auto e : s) {
    if (e == '0')
      zero += 1;
    else
      one += 1;
  }

  ans = min(zero, one) * 2;

  printf("%d\n", ans);

  return 0;
}
