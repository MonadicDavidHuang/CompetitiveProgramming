#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int q;

int main(void) {
  // Here your code !
  scanf("%d", &q);

  priority_queue<ll> left_set;
  priority_queue<ll, vector<ll>, greater<ll>> right_set;

  ll current = 0LL;

  for (int i = 0; i < q; ++i) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      ll a, b;
      scanf(" %lld %lld", &a, &b);

      current += b;

      if (left_set.empty()) {
        left_set.push(a);
        right_set.push(a);
        continue;
      }

      ll left = left_set.top();
      ll right = right_set.top();

      if (left <= a && a <= right) {
        left_set.push(a);
        right_set.push(a);
      } else if (a < left) {
        right_set.push(left_set.top());
        left_set.pop();

        left_set.push(a);
        left_set.push(a);

        current += left - a;
      } else {  // right < a
        left_set.push(right_set.top());
        right_set.pop();

        right_set.push(a);
        right_set.push(a);

        current += a - right;
      }

    } else {
      ll left = left_set.top();
      printf("%lld %lld\n", left, current);
    }
  }

  return 0;
}
