#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int d, t, s;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &d, &t, &s);

  if (s * t >= d) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
