#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

map<ll, unordered_map<ll, ll>> memo;

/////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////

int n;
ll a[MAX_N];

ll ans;

ll forward_vec[MAX_N];
ll backward_vec[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  forward_vec[0] = a[0];
  for (int i = 1; i < n; ++i) {
    forward_vec[i] = gcd(forward_vec[i - 1], a[i]);
  }

  backward_vec[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    backward_vec[i] = gcd(backward_vec[i + 1], a[i]);
  }

  ans = -1;

  for (int i = 0; i < n; ++i) {
    int left = i - 1;
    int right = i + 1;

    if (left < 0) {
      ans = max(ans, backward_vec[right]);
    } else if (right >= n) {
      ans = max(ans, forward_vec[left]);
    } else {
      ans = max(ans, gcd(forward_vec[left], backward_vec[right]));
    }
  }

  printf("%lld\n", ans);

  return 0;
}
