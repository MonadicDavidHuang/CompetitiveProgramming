#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a, b, c;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &a, &b, &c);

  set<int> visited;

  visited.insert(a % b);

  for (int i = 2; i <= 100; ++i) {
    int tmp = (a * i) % b;
    if (visited.find(tmp) != visited.end()) {
      break;
    }
    visited.insert(tmp);
  }

  if (visited.find(c) != visited.end()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
