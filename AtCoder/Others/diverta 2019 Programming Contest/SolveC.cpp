#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e4 + 5);

int n;
vector<string> ss;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ss.push_back(s);
  }

  int base = 0;

  int end_with_a = 0;
  int begin_with_b = 0;
  int end_with_a_begin_with_b = 0;

  for (auto s : ss) {
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == 'A' && s[i + 1] == 'B') base += 1;
    }
    if (s.back() == 'A' && s[0] == 'B') {
      end_with_a_begin_with_b += 1;
    } else if (s.back() == 'A') {
      end_with_a += 1;
    } else if (s[0] == 'B') {
      begin_with_b += 1;
    }
  }

  ans = base;

  if (end_with_a_begin_with_b > 0) {
    ans += end_with_a_begin_with_b - 1;

    if (end_with_a > 0) {
      ans += 1;
      end_with_a -= 1;
    }

    if (begin_with_b > 0) {
      ans += 1;
      begin_with_b -= 1;
    }

    ans += min(end_with_a, begin_with_b);
  } else {
    ans += min(end_with_a, begin_with_b);
  }

  printf("%d\n", ans);

  return 0;
}
