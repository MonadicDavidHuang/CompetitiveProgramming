#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

double s[3], e[3];

int ans;

int main(void) {
  // Here your code !
  for (int i = 0; i < 3; ++i) {
    scanf("%lf %lf", &(s[i]), &(e[i]));
  }

  for (int i = 0; i < 3; ++i) {
    ans += s[i] * e[i];
  }

  ans /= 10;

  printf("%d\n", ans);

  return 0;
}
