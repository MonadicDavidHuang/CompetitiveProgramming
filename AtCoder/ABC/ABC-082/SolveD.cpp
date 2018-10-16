#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int x, y;

bool check(vector<int>& dir, int goal, int start) {
  set<int> last;

  last.insert(start);

  for (auto& e : dir) {
    set<int> cur;

    for (auto& d : last) {
      cur.insert(d + e);
      cur.insert(d - e);
    }

    last = cur;
  }

  return last.find(goal) != last.end();
}

int main(void) {
  // Here your code !
  cin >> s;

  if (s.back() == 'F') s.push_back('T');

  scanf("%d %d", &x, &y);

  vector<int> dir_x;
  vector<int> dir_y;

  int parity = 0;
  int cur = 0;

  for (auto& e : s) {
    if (e == 'T') {
      if (parity % 2 == 0) {  // direction: x
        dir_x.push_back(cur);
      } else {  // direction: y
        dir_y.push_back(cur);
      }
      cur = 0;
      parity += 1;
    } else {
      cur += 1;
    }
  }

  int beg_x = 0;
  int beg_y = 0;

  if (s[0] == 'F') {
    beg_x += dir_x[0];
    dir_x.erase(dir_x.begin());
  }

  if (check(dir_x, x, beg_x) && check(dir_y, y, beg_y)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
