#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

ll l[MAX_N];
ll r[MAX_N];

inline bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
  return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(l[i]), &(r[i]));
  }

  if (n == 2) {
    ll ans = (r[0] - l[0] + 1L) + (r[1] - l[1] + 1L);
    printf("%lld\n", ans);
    return 0;
  }

  int max_l_ind = 0;
  int min_r_ind = 0;

  for (int i = 1; i < n; ++i) {
    if (l[i] > l[max_l_ind]) max_l_ind = i;
    if (r[i] < r[min_r_ind]) min_r_ind = i;
  }

  ll ans = 0L;

  // for case that a part of group is singleton
  for (int i = 0; i < n; ++i) {
    if (i == min_r_ind || i == max_l_ind) continue;

    ans =
        max(ans, max(r[min_r_ind] - l[max_l_ind] + 1, 0LL) + r[i] - l[i] + 1L);
  }

  vector<pair<ll, ll>> p;

  for (int i = 0; i < n; ++i) {
    if (i == min_r_ind || i == max_l_ind) continue;

    pair<ll, ll> tmp;

    tmp.first = max(r[min_r_ind] - l[i] + 1L, 0LL);   // first: fixed right
    tmp.second = max(r[i] - l[max_l_ind] + 1L, 0LL);  // second: fixed left

    p.push_back(tmp);
  }

  ll singleton_fixed_right = r[min_r_ind] - l[min_r_ind] + 1L;
  ll singleton_fixed_left = r[max_l_ind] - l[max_l_ind] + 1L;

  sort(p.begin(), p.end(), cmp);

  ans = max(ans, singleton_fixed_left +
                     p[0].first);  // all fixed right to T, except a fixed left
                                   // which belongs to S

  for (int i = 0; i < p.size(); ++i) {
    ans = max(ans, p[i].second);
  }

  ll part = p[0].second;
  for (int i = 1; i < p.size(); ++i) {
    ans = max(ans, part + p[i].first);
    part = min(part, p[i].second);
  }

  ans =
      max(ans, singleton_fixed_right + part);  // all fixed left to T, except a
                                               // fixed right which belongs to S

  printf("%lld\n", ans);

  return 0;
}
