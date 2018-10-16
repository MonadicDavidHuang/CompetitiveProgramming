#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b, c;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &a, &b, &c);

  if ((a <= c && c <= b) || (b <= c && c <= a)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
