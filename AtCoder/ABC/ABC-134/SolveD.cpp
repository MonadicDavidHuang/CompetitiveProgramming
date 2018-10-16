#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n;
int a[MAX_N];

vector<vector<int>> store(MAX_N);
int cnt[MAX_N];
int b[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      store[j].push_back(i);
    }
  }

  for (int i = n; i >= 1; --i) {
    if (cnt[i] % 2 != a[i]) {
      // printf("%d %d %d\n", i, cnt[i], a[i]);
      b[i] += 1;
      for (auto &e : store[i]) {
        cnt[e] += 1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] != cnt[i] % 2) {
      printf("%d\n", -1);
      return 0;
    }
  }

  // printf("a: ");
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", a[i]);
  // }
  // printf("\n");

  // printf("c: ");
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", cnt[i]);
  // }
  // printf("\n");

  for (int i = 1; i <= n; ++i) {
    ans += b[i];
  }

  printf("%d\n", ans);

  if (ans == 0) {
    return 0;
  }

  // printf("b: ");
  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  // printf("--------\n");

  return 0;
}
