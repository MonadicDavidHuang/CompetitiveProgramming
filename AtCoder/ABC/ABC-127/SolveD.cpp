#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;
ll a[MAX_N];
vector<pair<ll, int>> cb;

unordered_map<ll, int> cnt;

set<ll> cand;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &(a[i]));

    cnt[a[i]] += 1;

    cand.insert(a[i]);
  }

  for (int i = 1; i <= m; ++i) {
    int b;
    ll c;

    scanf("%d %lld", &b, &c);

    cb.push_back(make_pair(c, b));
    cand.insert(c);
  }

  sort(cb.begin(), cb.end());

  for (auto &e : cb) {
    cnt[e.first] += e.second;
  }

  vector<ll> cand_vec;

  for (auto e : cand) {
    cand_vec.push_back(e);
  }

  reverse(cand_vec.begin(), cand_vec.end());

  ll cnt_num = 0;

  int remain_card = n;
  for (auto e : cand_vec) {
    int num = min(remain_card, cnt[e]);

    remain_card -= num;

    cnt_num += e * num;

    if (n == 0) break;
  }

  ans = cnt_num;

  printf("%lld\n", ans);

  return 0;
}
