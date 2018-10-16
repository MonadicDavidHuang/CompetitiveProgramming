#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
    printf("Bad\n");
  } else {
    printf("Good\n");
  }

  return 0;
}
