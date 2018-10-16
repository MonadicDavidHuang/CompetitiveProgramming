#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;
string s;

int main(void) {
  // Here your code !

  scanf("%d %d", &n, &k);

  cin >> s;

  s[k - 1] = s[k - 1] - ('A' - 'a');

  cout << s << endl;

  return 0;
}
