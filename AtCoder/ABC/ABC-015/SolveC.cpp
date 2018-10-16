#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e0 + 5);
const int MAX_K = (int)(5e0 + 5);

int n, k;
int t[MAX_N][MAX_K];

bool check(int cnt, int acc) {
  if (cnt == n) {
    return (acc == 0);
  }

  for (int i = 0; i < k; ++i) {
    if (check(cnt + 1, acc ^ t[cnt][i])) {
      return true;
    }
  }

  return false;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &(t[i][j]));
    }
  }

  if (check(0, 0)) {
    printf("Found\n");
  } else {
    printf("Nothing\n");
  }

  return 0;
}
