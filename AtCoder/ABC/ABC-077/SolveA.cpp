#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s1, s2;

int main(void) {
  // Here your code !
  cin >> s1;
  cin >> s2;

  for (int i = 0; i < 3; ++i) {
    if (s1[i] != s2[2 - i]) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
