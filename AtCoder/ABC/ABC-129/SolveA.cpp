#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int al[5];

int main(void) {
  // Here your code !
  scanf("%d %d %d", &(al[0]), &(al[1]), &(al[2]));

  sort(al, al + 3);

  printf("%d\n", al[0] + al[1]);

  return 0;
}
