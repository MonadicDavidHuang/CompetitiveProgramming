#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
string c;

map<int, char> commands;

int solve(char l1, char l2, char r1, char r2) {
  vector<int> dp(n + 3, n);

  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    dp[i] = min(dp[i - 1] + 1, dp[i]);

    if (i - 2 >= 0) {
      bool condl = c[i - 1 - 1] == l1 && c[i - 0 - 1] == l2;
      bool condr = c[i - 1 - 1] == r1 && c[i - 0 - 1] == r2;
      if (condl || condr) {
        dp[i] = min(dp[i], dp[i - 2] + 1);
      }
    }
  }

  return dp[n];
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  cin >> c;

  commands[0] = 'A';
  commands[1] = 'B';
  commands[2] = 'X';
  commands[3] = 'Y';

  int ans = n;

  for (int i1 = 0; i1 < 4; ++i1) {
    for (int i2 = 0; i2 < 4; ++i2) {
      for (int i3 = 0; i3 < 4; ++i3) {
        for (int i4 = 0; i4 < 4; ++i4) {
          ans = min(ans, solve(commands[i1], commands[i2], commands[i3], commands[i4]));
        }
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
