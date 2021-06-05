#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e2 + 5);

int n;
int a[MAX_N];

int dp[MAX_N][200];

vector<vector<int>> candidates;

int get_valid_modulo() {
  if (dp[n][0] >= 3) return 0;

  for (int i = 1; i < 200; ++i) {
    if (dp[n][i] >= 2) return i;
  }

  return -1;
}

bool dfs(int cur, int modulo, vector<int> &hold) {
  if (cur == 0 && modulo == 0) {
    if (hold.empty()) return false;

    vector<int> tmp(hold);
    candidates.push_back(tmp);

    return candidates.size() >= 2;
  }

  if (cur == 0) return false;

  // do not use
  if (dp[cur - 1][modulo] != 0) {
    bool done = dfs(cur - 1, modulo, hold);
    if (done) return true;
  }

  // use
  hold.push_back(cur);
  int prev_modulo = (modulo - a[cur] + 200) % 200;
  if (dp[cur - 1][prev_modulo] != 0) {
    bool done = dfs(cur - 1, prev_modulo, hold);
    if (done) return true;
  }
  hold.pop_back();

  return false;
}

void retrieve(int modulo) {
  vector<int> hold;
  dfs(n, modulo, hold);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] %= 200;
  }

  // initialize
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 200; ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 200; ++j) {
      if (dp[i - 1][j] == 0) continue;

      int next_modulo = (j + a[i]) % 200;
      dp[i][next_modulo] += dp[i - 1][j];  // use a[i]
      dp[i][j] += dp[i - 1][j];            // do not use a[i]

      dp[i][next_modulo] = min(dp[i][next_modulo], 3);
      dp[i][j] = min(dp[i][j], 3);
    }
  }

  int modulo = get_valid_modulo();

  if (modulo < 0) {
    printf("No\n");
    return 0;
  }

  printf("Yes\n");

  retrieve(modulo);

  printf("%d ", candidates[0].size());
  sort(candidates[0].begin(), candidates[0].end());
  for (auto e : candidates[0]) {
    printf("%d ", e);
  }
  printf("\n");

  printf("%d ", candidates[1].size());
  sort(candidates[1].begin(), candidates[1].end());
  for (auto e : candidates[1]) {
    printf("%d ", e);
  }
  printf("\n");

  return 0;
}
