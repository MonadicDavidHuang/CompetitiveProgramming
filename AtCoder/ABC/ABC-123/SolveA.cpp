#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e1 + 5);

int a[MAX_N];
int k;

int main(void) {
  // Here your code !
  for (int i = 0; i < 5; ++i) {
    scanf("%d", &(a[i]));
  }
  scanf("%d", &k);

  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      if (abs(a[i] - a[j]) > k) {
        printf(":(\n");
        return 0;
      }
    }
  }

  printf("Yay!\n");

  return 0;
}
