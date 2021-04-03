#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e17 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;

ll x[MAX_N];
int c[MAX_N];

ll dp[MAX_N][2];  // dp[i][0]: end color i at left, dp[i][1]: end color i at right

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %d", &x[i], &c[i]);
  }

  set<int> col_set;

  for (int i = 0; i < n; ++i) {
    col_set.insert(c[i]);
  }

  int cnt = 0;

  unordered_map<int, int> dense;

  for (auto c : col_set) {
    cnt += 1;
    dense[c] = cnt;
  }

  int last_col = cnt;

  for (int i = 0; i < n; ++i) {
    c[i] = dense[c[i]];
  }

  ll most_left[MAX_N];
  ll most_right[MAX_N];
  fill(most_left, most_left + n + 5, INF);
  fill(most_right, most_right + n + 5, -INF);

  for (int i = 0; i < n; ++i) {
    most_left[c[i]] = min(most_left[c[i]], x[i]);
    most_right[c[i]] = max(most_right[c[i]], x[i]);
  }

  most_left[0] = 0;
  most_right[0] = 0;

  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int col = 1; col <= last_col; ++col) {
    ll last_right = most_right[col - 1];
    ll last_left = most_left[col - 1];
    ll cur_right = most_right[col];
    ll cur_left = most_left[col];

    // last right to current left / right
    if (last_right < cur_left) {
      dp[col][0] = dp[col - 1][1] + (cur_right - last_right) + (cur_right - cur_left);
      dp[col][1] = dp[col - 1][1] + (cur_right - last_right);
    } else if (cur_left < last_right && last_right < cur_right) {
      dp[col][0] = dp[col - 1][1] + (cur_right - last_right) + (cur_right - cur_left);
      dp[col][1] = dp[col - 1][1] + (last_right - cur_left) + (cur_right - cur_left);
    } else if (cur_right < last_right) {
      dp[col][0] = dp[col - 1][1] + (last_right - cur_left);
      dp[col][1] = dp[col - 1][1] + (last_right - cur_left) + (cur_right - cur_left);
    }

    // last left to current left / right
    if (last_left < cur_left) {
      dp[col][0] = min(dp[col][0], dp[col - 1][0] + (cur_right - last_left) + (cur_right - cur_left));
      dp[col][1] = min(dp[col][1], dp[col - 1][0] + (cur_right - last_left));
    } else if (cur_left < last_left && last_left < cur_right) {
      dp[col][0] = min(dp[col][0], dp[col - 1][0] + (cur_right - last_left) + (cur_right - cur_left));
      dp[col][1] = min(dp[col][1], dp[col - 1][0] + (last_left - cur_left) + (cur_right - cur_left));
    } else if (cur_right < last_left) {
      dp[col][0] = min(dp[col][0], dp[col - 1][0] + (last_left - cur_left));
      dp[col][1] = min(dp[col][1], dp[col - 1][0] + (last_left - cur_left) + (cur_right - cur_left));
    }
  }

  ll cand_last_left = abs(most_left[last_col] - 0) + dp[last_col][0];
  ll cand_last_right = abs(most_right[last_col] - 0) + dp[last_col][1];

  ll ans = min(cand_last_left, cand_last_right);

  printf("%lld\n", ans);

  return 0;
}
