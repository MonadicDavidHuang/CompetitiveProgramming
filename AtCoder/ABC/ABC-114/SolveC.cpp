#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;

int ans = 0;

/////////////////////////////////////////////////////////////
ll mypow_core(ll x, int n, ll result) {
  if (n == 0) {
    return result;
  }

  if (n % 2 == 0) {
    return mypow_core(x * x, n / 2, result);
  } else {
    return mypow_core(x, n - 1, x * result);
  }
}

ll mypow(ll x, int n) { return mypow_core(x, n, 1); }
/////////////////////////////////////////////////////////////

void rec(int digit_num, int cnt, ll acc, bool three, bool five, bool seven) {
  if (three && five && seven) {
    if (1 <= acc && acc <= n) ans += 1;
  }

  if (cnt == digit_num) {
    return;
  } else {
    rec(digit_num, cnt + 1, acc + 3 * mypow(10, cnt), true, five, seven);
    rec(digit_num, cnt + 1, acc + 5 * mypow(10, cnt), three, true, seven);
    rec(digit_num, cnt + 1, acc + 7 * mypow(10, cnt), three, five, true);
  }
}

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  rec(log10(n) + 2, 0, 0, false, false, false);

  printf("%d\n", ans);

  return 0;
}
