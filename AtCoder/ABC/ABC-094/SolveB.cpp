#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);
const int MAX_M = (int)(1e2 + 5);

int n, m, x;
set<int> set_a;

int acc[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &n, &m, &x);

  for (int i = 1; i <= m; ++i) {
    int a;
    scanf("%d", &a);

    set_a.insert(a);
  }

  int fst = 0;

  for (int i = x; i <= n; ++i) {
    if (set_a.find(i) != set_a.end()) {
      fst += 1;
    }
  }

  int snd = 0;

  for (int i = x; i >= 0; --i) {
    if (set_a.find(i) != set_a.end()) {
      snd += 1;
    }
  }

  printf("%d\n", min(fst, snd));

  return 0;
}
