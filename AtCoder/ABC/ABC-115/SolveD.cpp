#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(50 + 5);

int n;
ll x;

ll putty[MAX_N];
ll burger[MAX_N];

ll ans;

ll eat_layer_burger(int layer, ll remain) {
  if (remain == 1) return 0;

  remain -= 1;

  if (remain < burger[layer - 1]) {
    return eat_layer_burger(layer - 1, remain);
  } else if (remain == burger[layer - 1]) {
    return putty[layer - 1];
  } else if (remain == burger[layer - 1] + 1) {
    return putty[layer - 1] + 1;
  } else if (remain < 2 * burger[layer - 1] + 1) {
    ll upper = eat_layer_burger(layer - 1, remain - burger[layer - 1] - 1);
    return putty[layer - 1] + 1 + upper;
  } else {
    return putty[layer];
  }
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &x);

  putty[0] = 1;
  for (int i = 1; i <= 50; ++i) {
    putty[i] = putty[i - 1] * 2 + 1;
  }

  burger[0] = 1;
  for (int i = 1; i <= 50; ++i) {
    burger[i] = burger[i - 1] * 2 + 3;
  }

  ans = eat_layer_burger(n, x);

  printf("%lld\n", ans);

  return 0;
}
