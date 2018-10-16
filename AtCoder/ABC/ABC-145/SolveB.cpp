#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
string s;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  cin >> s;

  if (n % 2 == 1) {
    printf("No\n");
    return 0;
  }

  int half = n / 2;

  for (int i = 0; i < half; ++i) {
    if (s[i] != s[half + i]) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
