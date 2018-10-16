#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string x;

int main(void) {
  // Here your code !
  cin >> x;

  stack<char> stk;

  for (auto &e : x) {
    if (stk.empty()) {
      stk.push(e);
      continue;
    }

    if (e == 'T' && stk.top() == 'S') {
      stk.pop();
      continue;
    }

    stk.push(e);
  }

  int ans = 0;

  while (!stk.empty()) {
    ans += 1;
    stk.pop();
  }

  printf("%d\n", ans);

  return 0;
}
