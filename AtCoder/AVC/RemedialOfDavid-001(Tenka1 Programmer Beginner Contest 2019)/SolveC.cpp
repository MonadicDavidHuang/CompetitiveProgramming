#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
string s;

int white[MAX_N];
int black[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);
  cin >> s;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '#') {
      black[i] = 1;
    } else {
      white[i] = 1;
    }
  }

  for (int i = 1; i < n; ++i) {
    black[i] = black[i] + black[i - 1];
  }

  for (int i = 1; i < n; ++i) {
    white[i] = white[i] + white[i - 1];
  }

  int all_black = black[n - 1];
  int all_white = white[n - 1];

  ans = min(n - all_black, n - all_white);

  for (int i = 0; i < n; ++i) {
    int left_b = black[i];
    int left_w = white[i];

    int right_b = all_black - left_b;
    int right_w = all_white - left_w;

    // case: w, w
    ans = min(ans, left_b + right_b);

    // case: w, b
    ans = min(ans, left_b + right_w);

    // case: b, b
    ans = min(ans, left_w + right_w);
  }

  printf("%d\n", ans);

  return 0;
}
