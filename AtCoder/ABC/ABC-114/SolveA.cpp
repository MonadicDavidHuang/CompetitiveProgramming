#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int x;

int main(void) {
  // Here your code !
  scanf("%d", &x);

  if (x == 3 || x == 5 || x == 7) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
