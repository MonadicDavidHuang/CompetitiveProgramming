#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !

  cin >> s;

  deque<int> dq;

  for (auto &e : s) {
    dq.push_back(e);
  }

  int ans = 0;

  while (!dq.empty()) {
    if (dq.front() == dq.back()) {
      dq.pop_front();

      if (!dq.empty()) {
        dq.pop_back();
      }
    } else if (dq.front() == 'x') {
      dq.push_back('x');
      ans += 1;
    } else if (dq.back() == 'x') {
      dq.push_front('x');
      ans += 1;
    } else {
      printf("%d\n", -1);
      return 0;
    }
  }

  printf("%d\n", ans);

  return 0;
}
