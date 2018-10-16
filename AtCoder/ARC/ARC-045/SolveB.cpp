#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;

int s[MAX_M];
int t[MAX_M];

int imos[MAX_N];
int accum[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &(s[i]), &(t[i]));
  }

  for (int i = 0; i < m; ++i) {
    imos[s[i]] += 1;
    imos[t[i] + 1] -= 1;
  }

  for (int i = 1; i <= n; ++i) {
    imos[i] += imos[i - 1];
  }

  for (int i = 0; i <= n; ++i) {
    accum[i] = imos[i] > 1 ? 2 : imos[i];
  }

  for (int i = 1; i <= n; ++i) {
    accum[i] += accum[i - 1];
  }

  vector<int> ans;

  for (int i = 0; i < m; ++i) {
    int score = accum[t[i]] - accum[s[i] - 1];

    int range = t[i] - s[i] + 1;

    int score_when_escape = score - range;

    if (score_when_escape / range >= 1) ans.push_back(i + 1);
  }

  printf("%d\n", ans.size());

  for (auto &e : ans) {
    printf("%d\n", e);
  }

  return 0;
}
