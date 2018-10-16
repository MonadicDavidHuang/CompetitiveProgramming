#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll h[MAX_N];

ll h_no[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(h[i]));
  }

  for (int i = n - 2; i >= 0; --i) {
    if (h[i + 1] < h[i]) {
      h[i] -= 1;
    }

    if (h[i + 1] < h[i]) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
