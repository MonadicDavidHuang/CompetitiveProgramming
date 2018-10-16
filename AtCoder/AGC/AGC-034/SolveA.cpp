#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, a, b, c, d;
string s;

bool check_reach(int start, int end) {
  for (int i = start; i <= end - 1; ++i) {
    if (s[i] == '#' && s[i + 1] == '#') {
      return false;
    }
  }

  return true;
}

bool check_triple() {
  bool ret = false;
  for (int i = b; i <= d; ++i) {
    if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') ret = true;
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

  cin >> s;

  // s = '#' + s + '#';

  if (!check_reach(a, c) || !check_reach(b, d)) {
    printf("No\n");
    return 0;
  }

  if (c < d) {
    printf("Yes\n");
    return 0;
  }

  if (check_triple()) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
