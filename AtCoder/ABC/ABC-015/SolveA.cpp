#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string a, b;

int main(void) {
  // Here your code !
  cin >> a;
  cin >> b;

  if (a.size() > b.size()) {
    cout << a << endl;
  } else {
    cout << b << endl;
  }

  return 0;
}
