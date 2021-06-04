#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;
string s;

int main(void) {
  // Here your code !
  scanf("%d", &n);
  cin >> s;
  scanf("%d", &k);

  char target = s[k - 1];

  for (auto e : s) {
    if (e != target) {
      printf("*");
    } else {
      printf("%c", target);
    }
  }

  printf("\n");

  return 0;
}
