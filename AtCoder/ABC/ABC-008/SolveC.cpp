#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
ll c[MAX_N];

map<ll, int> cnt;

double ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(c[i]));
  }

  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (c[i] % c[j] == 0) cnt[i] += 1;
    }
  }

  ans = 0.0;

  for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
    if (itr->second == 0) {
      ans += 1.0;
      continue;
    }

    if (itr->second % 2 == 0) {
      double top = itr->second + 2;
      double bottom = 2 * itr->second + 2;
      ans += top / bottom;
    } else {
      ans += 0.5;
    }
  }

  printf("%.10lf\n", ans);

  return 0;
}
