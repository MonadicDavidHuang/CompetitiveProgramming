#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
int a;

int main(void) {
  // Here your code !
  scanf("%d", &n);
  scanf("%d", &a);

  if (n % 500 > a) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}
