#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e4 + 5);

int n, m;
vector<int> available;
vector<int> cand;

ll dp[MAX_N];

map<int, int> cost;

vector<int> ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int tmp;
    scanf("%d", &tmp);
    available.push_back(tmp);
  }

  cost[1] = 2;
  cost[2] = 5;
  cost[3] = 5;
  cost[4] = 4;
  cost[5] = 5;
  cost[6] = 6;
  cost[7] = 3;
  cost[8] = 7;
  cost[9] = 6;

  for (auto e : available) {
    cand.push_back(cost[e]);
  }

  for (int i = 0; i <= n; ++i) {
    dp[i] = -INF;
  }

  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (auto e : cand) {
      if (i - e >= 0) {
        dp[i] = max(dp[i], dp[i - e] + 1);
      }
    }
  }

  int i = n;
  while (i > 0) {
    int tmp = -1;
    int tmp_cost = 0;

    if (dp[i] - 1 == 0) {  // to gracefully use all match
      for (auto e : available) {
        if (i - cost[e] == 0 && dp[i - cost[e]] == dp[i] - 1) {
          if (e > tmp) {
            tmp_cost = cost[e];
            tmp = e;
          }
        }
      }
    } else {
      for (auto e : available) {
        if (i - cost[e] >= 0 && dp[i - cost[e]] == dp[i] - 1) {
          if (e > tmp) {
            tmp_cost = cost[e];
            tmp = e;
          }
        }
      }
    }

    ans.push_back(tmp);
    i -= tmp_cost;
  }

  for (auto e : ans) {
    printf("%d", e);
  }
  printf("\n");

  return 0;
}
