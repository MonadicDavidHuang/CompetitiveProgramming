#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, m;

bool contaminated[MAX_N];
int bole_num[MAX_N];

int ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  contaminated[1] = true;
  bole_num[1] = 1;

  for (int i = 2; i <= n; ++i) {
    contaminated[i] = false;
    bole_num[i] = 1;
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    int move_num = (bole_num[x] > 0) ? 1 : 0;

    if (contaminated[x]) {
      if (move_num == 1) {
        contaminated[y] = true;
        bole_num[x] -= move_num;
        bole_num[y] += move_num;
        if (bole_num[x] == 0) contaminated[x] = false;
      }
    } else {
      bole_num[x] -= move_num;
      bole_num[y] += move_num;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (contaminated[i]) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
