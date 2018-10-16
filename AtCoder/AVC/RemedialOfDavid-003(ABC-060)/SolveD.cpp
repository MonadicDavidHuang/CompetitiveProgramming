#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
ll bag;
map<ll, vector<ll>> mp;  // weight -> value

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &bag);

  for (int i = 0; i < n; ++i) {
    ll w, v;
    scanf("%lld %lld", &w, &v);
    mp[w].push_back(v);
  }

  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    sort((itr->second).begin(), (itr->second).end(), greater<ll>());
  }

  queue<pair<ll, ll>> last_que;  // weight, value
  queue<pair<ll, ll>> cur_que;   // weight, value

  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    ll key_weight = itr->first;
    auto values = itr->second;

    ll cur_weight = 0LL;
    ll cur_value = 0LL;

    vector<pair<ll, ll>> cur_acc_weight_values;

    cur_acc_weight_values.push_back(make_pair(cur_weight, cur_value));

    for (auto e : values) {
      cur_weight += key_weight;
      cur_value += e;
      cur_acc_weight_values.push_back(make_pair(cur_weight, cur_value));
    }

    if (last_que.empty()) {
      for (auto e : cur_acc_weight_values) {
        cur_que.push(e);
      }
    } else {
      while (!last_que.empty()) {
        auto last_front = last_que.front();
        last_que.pop();

        ll last_weight = last_front.first;
        ll last_value = last_front.second;

        for (auto e : cur_acc_weight_values) {
          cur_que.push(make_pair(last_weight + e.first, last_value + e.second));
        }
      }
    }

    last_que = cur_que;
    cur_que = queue<pair<ll, ll>>();
  }

  ans = -1;

  while (!last_que.empty()) {
    auto last_front = last_que.front();
    if (last_front.first <= bag) {
      ans = max(ans, last_front.second);
    }
    last_que.pop();
  }

  printf("%lld\n", ans);

  return 0;
}
