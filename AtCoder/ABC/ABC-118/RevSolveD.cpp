#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e4 + 5);

int n, m;
vector<int> vec_a;

int dp[MAX_N];
map<int, int> mp;

vector<int> ans;

void prepare() {
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;
}

int main(void) {
  // Here your code !
  prepare();

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    vec_a.push_back(a);
  }

  sort(vec_a.begin(), vec_a.end(), greater<int>());

  fill(dp, dp + n, -1);

  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    if (dp[i] < 0) continue;

    for (auto &e : vec_a) {
      dp[i + mp[e]] = max(dp[i + mp[e]], dp[i] + 1);
    }
  }

  int i = n;

  while (i > 0) {
    for (auto &e : vec_a) {
      if (i >= mp[e] && dp[i - mp[e]] == (dp[i] - 1)) {
        ans.push_back(e);
        i -= mp[e];
        break;
      }
    }
  }

  for (auto &e : ans) {
    printf("%d", e);
  }
  printf("\n");

  return 0;
}
