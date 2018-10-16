#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e3 + 5);
const int MAX_T = (int)(3e3 + 5);

int n, t;

vector<pair<int, int>> ab;

int dp_l[MAX_N][MAX_T];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &t);

  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ab.push_back(make_pair(a, b));
  }

  sort(ab.begin(), ab.end());

  ab.insert(ab.begin(), make_pair(-1, -1));

  for (int i = 1; i <= n; ++i) {
    for (int c = 1; c <= t; ++c) {
      if (c < ab[i].first) {
        dp_l[i][c] = dp_l[i - 1][c];
      } else {
        dp_l[i][c] =
            max(dp_l[i - 1][c], dp_l[i - 1][c - ab[i].first] + ab[i].second);
      }
    }
  }

  int ans = -1;

  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp_l[i - 1][t - 1] + ab[i].second);
  }

  printf("%d\n", ans);

  return 0;
}
