#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

map<char, int> cnt;

int odd, even;

int ans;

int main(void) {
  // Here your code !
  cin >> s;

  for (auto &e : s) {
    cnt[e] += 1;
  }

  odd = 0;
  even = 0;

  for (auto &e : cnt) {
    if (e.second % 2 == 1) {
      odd += 1;
      even += e.second - (e.second % 2);
    } else {
      even += e.second;
    }
  }

  int half = even / 2;

  if (odd == 0) {
    ans = even;
  } else {
    int wing = half / odd;

    ans = 1 + wing * 2;
  }

  printf("%d\n", ans);

  return 0;
}
