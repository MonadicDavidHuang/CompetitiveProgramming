#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string fuck;
string shit;

int main(void) {
  // Here your code !
  cin >> fuck;
  cin >> shit;

  ll a = 0LL;

  for (int i = 0; i < fuck.size(); ++i) {
    a *= 10LL;
    a += (ll)(fuck[i] - '0');
  }

  ll x10b = 100LL * (ll)(shit[0] - '0') + 10LL * (ll)(shit[2] - '0') + 1LL * (ll)(shit[3] - '0');

  ll ans = a * x10b / 100LL;

  printf("%lld\n", ans);

  return 0;
}
