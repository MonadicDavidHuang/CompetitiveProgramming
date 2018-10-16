#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int d;

int main(void) {
  // Here your code !
  scanf("%d", &d);

  if (d == 25) {
    printf("Christmas\n");
  } else if (d == 24) {
    printf("Christmas Eve\n");
  } else if (d == 23) {
    printf("Christmas Eve Eve\n");
  } else {
    printf("Christmas Eve Eve Eve\n");
  }

  return 0;
}
