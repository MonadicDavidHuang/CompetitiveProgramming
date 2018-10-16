#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll k;
int q;

int win[MAX_N];

ll score[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %lld %d", &n, &k, &q);

  for (int i = 0; i < q; ++i) {
    int a;
    scanf("%d", &a);
    win[a] += 1;
  }

  for (int i = 1; i <= n; ++i) {
    score[i] = k - (ll)(q - win[i]);
  }

  for (int i = 1; i <= n; ++i) {
    if (score[i] > 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
