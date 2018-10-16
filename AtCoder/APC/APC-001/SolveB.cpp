#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e4 + 5);

int n;

ll a[MAX_N], b[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(b[i]));
  }

  ll bank_a = 0LL;
  ll bank_b = 0LL;

  for (int i = 0; i < n; ++i) {
    ll diff = a[i] - b[i];

    if (diff == 0LL) continue;

    if (diff < 0LL) {
      ll need_a = abs(diff / 2LL);
      ll use_a = min(bank_a, need_a);

      bank_a -= use_a;
      bank_b += need_a - use_a;
    } else {
      ll need_b = diff;
      ll use_b = min(bank_b, need_b);

      bank_b -= use_b;
      bank_a += need_b - use_b;
    }
  }

  string ans = (bank_a * 2 <= bank_b) ? "Yes" : "No";

  cout << ans << endl;

  return 0;
}
