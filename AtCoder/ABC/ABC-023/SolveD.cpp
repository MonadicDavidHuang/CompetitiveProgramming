#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll h[MAX_N];
ll s[MAX_N];

bool check(ll mid) {
  vector<pair<double, int>> cand;
  for (int i = 0; i < n; ++i) {
    double time = ((double)(mid - h[i])) / ((double)(s[i]));

    if (time < 0) return false;

    cand.push_back(make_pair(time, i));
  }

  sort(cand.begin(), cand.end());

  for (int i = 1; i < n; ++i) {
    int index = cand[i].second;
    ll pos = h[index] + s[index] * i;
    if (pos > mid) return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d\n", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(h[i]), &(s[i]));
  }

  ll ok = (ll)(1e15 + 5);
  ll ng = 0;

  while (abs(ok - ng) > 1) {
    ll next = (ok + ng) / 2;
    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  printf("%lld\n", ok);

  return 0;
}
