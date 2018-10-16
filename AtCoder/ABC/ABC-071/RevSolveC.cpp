#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

map<ll, int> cnt;
priority_queue<ll> que;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    ll tmp;
    scanf("%lld", &tmp);

    cnt[tmp] += 1;
  }

  for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
    for (int i = 0; i < itr->second / 2; ++i) {
      que.push(itr->first);
    }
  }

  if (que.empty()) {
    printf("%lld\n", 0);
    return 0;
  }

  ll first = que.top();
  que.pop();

  if (que.empty()) {
    printf("%lld\n", 0);
    return 0;
  }

  ll second = que.top();
  que.pop();

  printf("%lld\n", first * second);

  return 0;
}
