#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll a, b, x;

bool check(ll n) {
  string nstr = to_string(n);
  ll need = a * n + b * (ll)(nstr.size());

  return need <= x;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld %lld", &a, &b, &x);

  if (!check(0LL)) {
    printf("0\n");
    return 0;
  }

  ll ok = 0LL;
  ll ng = (ll)(1e9 + 1);

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2LL;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  printf("%lld\n", ok);

  return 0;
}
