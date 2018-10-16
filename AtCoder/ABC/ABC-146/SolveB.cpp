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

  for (int i = 0; i < s.size(); ++i) {
    int tmp = s[i] - 'A';

    tmp += n;

    tmp %= 26;

    s[i] = (char)((int)('A') + tmp);
  }

  cout << s << endl;

  return 0;
}
