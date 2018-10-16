#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

map<char, int> mp;

int main(void) {
  // Here your code !
  cin >> s;

  for (auto e : s) {
    mp[e] += 1;
  }

  if (mp.size() == 2) {
    bool flg = true;
    for (auto e : mp) {
      flg &= (e.second == 2);
    }

    if (flg) {
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");

  return 0;
}
