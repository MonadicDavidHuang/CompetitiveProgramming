#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MOD = (ll)(1e9 + 7);

int n, m;
int f[MAX_N];

ll score[MAX_N];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(f[i]));
  }

  f[0] = -1;

  unordered_map<int, int> app_r;
  unordered_map<int, int> app_l;

  score[0] = 1;
  score[1] = 1;

  app_r[f[0]] += 1;
  app_r[f[1]] += 1;

  app_l[f[0]] += 1;

  int left = 0;

  ll sum = score[0] + score[1];

  for (int i = 2; i <= n + 1; ++i) {
    app_r[f[i]] += 1;

    while ((app_r[f[i]] - app_l[f[i]]) >= 2) {
      sum -= score[left];
      sum %= MOD;
      if (sum < 0) sum += MOD;

      left += 1;

      app_l[f[left]] += 1;
    }

    score[i] = sum;

    sum += score[i];
    sum %= MOD;
  }

  ans = score[n];

  printf("%lld\n", ans);

  return 0;
}
