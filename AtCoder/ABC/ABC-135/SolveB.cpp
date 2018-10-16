#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n;
int p[MAX_N];

int q[MAX_N];

bool check() {
  for (int i = 1; i < n; ++i) {
    if (q[i - 1] > q[i]) return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(p[i]));
  }

  for (int i = 0; i < n; ++i) {
    q[i] = p[i];
  }

  if (check()) {
    printf("YES\n");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int i = 0; i < n; ++i) {
        q[i] = p[i];
      }

      int tmp = p[i];
      q[i] = q[j];
      q[j] = tmp;

      if (check()) {
        printf("YES\n");
        return 0;
      }
    }
  }

  printf("NO\n");

  return 0;
}
