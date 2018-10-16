#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int h, w, n;
int x, y;
string s, t;

string ans;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &h, &w, &n);
  scanf("%d %d", &x, &y);
  cin >> s;
  cin >> t;

  ans = "YES";

  int h1 = 1, h2 = h;
  int w1 = 1, w2 = w;

  for (int i = n - 1; i >= 0; --i) {
    if (t[i] == 'D') {
      h1 = max(1, h1 - 1);
    } else if (t[i] == 'U') {
      h2 = min(h, h2 + 1);
    } else if (t[i] == 'R') {
      w1 = max(1, w1 - 1);
    } else {  // t[i] == 'L'
      w2 = min(w, w2 + 1);
    }

    if (s[i] == 'D') {
      h2 -= 1;
    } else if (s[i] == 'U') {
      h1 += 1;
    } else if (s[i] == 'R') {
      w2 -= 1;
    } else {  // s[i] == 'L'
      w1 += 1;
    }

    if (h1 > h2 || w1 > w2) {
      printf("NO\n");
      return 0;
    }

    // printf("%d %d : %d %d\n", h1, h2, w1, w2);
  }

  if (h1 <= x && x <= h2 && w1 <= y && y <= w2) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
