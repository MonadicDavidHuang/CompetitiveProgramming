#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
map<char, int> ans;

map<char, int> shape(string s) {
  map<char, int> mp;
  for (auto e : s) {
    mp[e] += 1;
  }
  return mp;
}

void merge(map<char, int> inpt) {
  map<char, int> newans;
  for (auto &e : inpt) {
    if (ans.find(e.first) != ans.end()) {
      newans[e.first] = min(ans[e.first], e.second);
    }
  }
  ans = newans;
}

int main(void) {
  // Here your code !
  scanf("%d\n", &n);
  string fst;
  cin >> fst;
  ans = shape(fst);
  for (int i = 2; i <= n; ++i) {
    string tmp;
    cin >> tmp;
    auto inpt = shape(tmp);
    merge(inpt);
  }

  for (auto &e : ans) {
    for (int i = 0; i < e.second; ++i) {
      printf("%c", e.first);
    }
  }

  printf("\n");

  return 0;
}
