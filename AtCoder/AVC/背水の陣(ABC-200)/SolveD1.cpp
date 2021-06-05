#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e2 + 5);

int n;
ll a[MAX_N];

ll dp[MAX_N][201];

unordered_map<ll, vector<ll>> with_node;
unordered_map<ll, vector<ll>> wo_node;

vector<vector<int>> candidates;

pair<int, int> decode(ll encoded) {
  int i = (int)(encoded / 200LL);
  int modulo = (int)(encoded % 200LL);

  return make_pair(i, modulo);
}

ll encode(int i, int modulo) {
  return ll(i * 200 + modulo);
}

int get_valid_modulo() {
  if (dp[n][0] >= 3) return 0;

  for (int i = 1; i < 200; ++i) {
    if (dp[n][i] >= 2) return i;
  }

  return -1;
}

bool dfs(ll cur, vector<int> &hold) {
  int used = decode(cur).first;
  int modulo = decode(cur).second;

  if (cur == encode(0, 0)) {
    if (hold.empty()) return false;

    vector<int> tmp(hold);
    candidates.push_back(tmp);

    return candidates.size() >= 2;
  }

  // use
  if (with_node.find(cur) != with_node.end()) {
    for (auto prev : with_node[cur]) {
      hold.push_back(used);

      bool done = dfs(prev, hold);
      if (done) return true;

      hold.pop_back();
    }
  }

  // do not use
  if (wo_node.find(cur) != wo_node.end()) {
    for (auto prev : wo_node[cur]) {
      bool done = dfs(prev, hold);
      if (done) return true;
    }
  }

  return false;
}

void retrieve(ll node) {
  vector<int> hold;
  dfs(node, hold);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }

  // initialize
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 200; ++j) {
      dp[i][j] = 0LL;
    }
  }
  dp[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 200; ++j) {
      if (dp[i - 1][j] == 0) continue;

      int cur_target_with = (int)(((ll)(j) + a[i]) % 200LL);
      int cur_target_wo = j;

      dp[i][cur_target_with] += dp[i - 1][j];  // use a[i]
      dp[i][cur_target_wo] += dp[i - 1][j];    // do not use a[i]

      dp[i][cur_target_with] = min(dp[i][cur_target_with], 3LL);
      dp[i][cur_target_wo] = min(dp[i][cur_target_wo], 3LL);

      ll last_node = encode(i - 1, j);
      ll cur_node_with = encode(i, cur_target_with);
      ll cur_node_wo = encode(i, j);

      with_node[cur_node_with].push_back(last_node);
      wo_node[cur_node_wo].push_back(last_node);
    }
  }

  int modulo = get_valid_modulo();

  if (modulo < 0) {
    printf("No\n");
    return 0;
  }

  printf("Yes\n");

  retrieve(encode(n, modulo));

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
