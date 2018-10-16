#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[3 * MAX_N];

priority_queue<ll, vector<ll>, greater<ll>> leftpq;
priority_queue<ll> rightpq;

ll l, r;
ll scorel[3 * MAX_N];
ll scorer[3 * MAX_N];
ll ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);
  for (int i = 0; i < 3 * n; ++i) {
    scanf("%lld", &a[i]);
  }

  for (int i = 0; i < n; ++i) {
    leftpq.push(a[i]);
    l += a[i];
  }
  scorel[n] = l;

  for (int i = 3 * n - 1; i >= 2 * n; --i) {
    rightpq.push(a[i]);
    r += a[i];
  }
  scorer[2 * n] = r;

  for (int i = n; i < 2 * n; ++i) {
    leftpq.push(a[i]);
    l += a[i];
    l -= leftpq.top();
    leftpq.pop();
    scorel[i + 1] = l;
  }

  for (int i = 2 * n - 1; i >= n; --i) {
    rightpq.push(a[i]);
    r += a[i];
    r -= rightpq.top();
    rightpq.pop();
    scorer[i] = r;
  }

  ans = scorel[n] - scorer[n];
  for (int i = n; i <= 2 * n; ++i) {
    ans = max(ans, scorel[i] - scorer[i]);
  }

  printf("%lld\n", ans);
  return 0;
}
