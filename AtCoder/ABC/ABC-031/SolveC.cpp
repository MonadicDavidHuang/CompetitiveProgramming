#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(100 + 5);

int n;
int a[MAX_N];

int ans = -(2500 + 5);

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    int a_score = -(2500 + 5);
    int t_score = -(2500 + 5);
    int choice = -1;

    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;

      int tmp_a = 0;
      int tmp_t = 0;

      int l = min(i, j);
      int r = max(i, j);

      int diff = r - l + 1;

      for (int k = 1; k <= diff; ++k) {
        tmp_a += (k % 2 == 0) ? a[l - 1 + k] : 0;
      }

      if (a_score < tmp_a) {
        for (int k = 1; k <= diff; ++k) {
          tmp_t += (k % 2 == 1) ? a[l - 1 + k] : 0;
        }

        a_score = tmp_a;
        t_score = tmp_t;

        choice = j;
      }
    }
    ans = max(ans, t_score);
  }

  printf("%d\n", ans);

  return 0;
}
