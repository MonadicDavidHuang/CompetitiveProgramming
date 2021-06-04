#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_K = (int)(1e6 + 5);

int k;
bool visited[MAX_K];

int main(void) {
  // Here your code !
  scanf("%d", &k);

  int cur = 7;
  int cnt = 1;

  while (true) {
    if (visited[cur]) {
      printf("-1\n");
      return 0;
    }

    if (cur % k == 0) {
      printf("%d\n", cnt);
      return 0;
    }

    visited[cur] = true;

    cur = (cur * 10 + 7) % k;

    cnt += 1;
  }

  return 0;
}
