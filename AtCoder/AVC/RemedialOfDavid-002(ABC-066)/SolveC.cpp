#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

deque<ll> dque;
vector<ll> ans;

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  for (int i = 1; i <= n; ++i) {
    int tmp;
    scanf("%lld", &tmp);

    if (i % 2 == 0) {
      dque.push_front(tmp);
    } else {
      dque.push_back(tmp);
    }
  }

  while (!dque.empty()) {
    ans.push_back(dque.front());
    dque.pop_front();
  }

  if (n % 2 == 1) {
    reverse(ans.begin(), ans.end());
  }

  for (auto e : ans) {
    printf("%lld ", e);
  }

  printf("\n");

  return 0;
}
