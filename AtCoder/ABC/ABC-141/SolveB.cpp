#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  for (int i = 0; i < s.size(); i += 2) {
    if (!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) {
      printf("No\n");
      return 0;
    }
  }

  for (int i = 1; i < s.size(); i += 2) {
    if (!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
