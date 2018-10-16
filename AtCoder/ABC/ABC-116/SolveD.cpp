#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;

vector<pair<ll, int>> td;

map<int, int> mp;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
    pque;

vector<ll> ans;

int main(void) {
  // Here your code !

  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    int t;
    ll d;
    scanf("%d %lld", &t, &d);

    td.push_back(make_pair(d, t));
  }

  sort(td.begin(), td.end(), greater<pair<ll, int>>());

  ll tmp_sum = 0;

  for (int i = 0; i < k; ++i) {
    mp[td[i].second] += 1;
    if (mp[td[i].second] > 1) {
      pque.push(make_pair(td[i].first, td[i].second));
    }
    tmp_sum += td[i].first;
  }

  ans.push_back(tmp_sum + pow(mp.size(), 2));

  for (int i = k; i < n; ++i) {
    if (mp.find(td[i].second) == mp.end() && !pque.empty()) {
      pair<ll, int> e = pque.top();
      pque.pop();

      mp[e.second] -= 1;
      tmp_sum -= e.first;

      mp[td[i].second] += 1;
      tmp_sum += td[i].first;

      ans.push_back(tmp_sum + powl(mp.size(), 2));
    }
  }

  ll last_ans = *max_element(ans.begin(), ans.end());

  printf("%lld\n", last_ans);

  return 0;
}
