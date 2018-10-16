#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, m;

unordered_map<int, int> cnt;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    cnt[a] += 1;
    cnt[b] += 1;
  }

  for (auto &e : cnt) {
    if (e.second % 2 == 1) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
