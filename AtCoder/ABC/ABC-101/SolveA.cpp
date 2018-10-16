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

  for (auto e : s) {
    if (e == '+')
      ans += 1;
    else
      ans -= 1;
  }

  printf("%d\n", ans);

  return 0;
}
