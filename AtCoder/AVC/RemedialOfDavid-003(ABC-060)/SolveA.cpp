#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string a, b, c;

int main(void) {
  // Here your code !
  cin >> a >> b >> c;

  if (a.back() == b[0] && b.back() == c[0]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
