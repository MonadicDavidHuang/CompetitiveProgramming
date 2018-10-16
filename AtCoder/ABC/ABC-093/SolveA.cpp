#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  sort(s.begin(), s.end());

  if (s[0] == 'a' && s[1] == 'b' && s[2] == 'c') {
    printf("Yes");
  } else {
    printf("No\n");
  }

  return 0;
}
