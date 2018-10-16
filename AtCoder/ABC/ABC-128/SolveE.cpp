#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

using event = tuple<ll, int, ll>;

const int MAX_Q = (int)(2e5 + 5);

int n, q;
ll d[MAX_Q];

priority_queue<event, vector<event>, greater<event>> events;

map<int, ll> ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    ll s, t, x;
    scanf("%lld %lld %lld", &s, &t, &x);

    events.push(make_tuple(s - x, 1, x));
    events.push(make_tuple(t - x, -1, x));
  }

  for (int i = 0; i < q; ++i) {
    scanf("%lld", &(d[i]));
  }

  set<ll> pos_set;

  for (int i = 0; i < q; ++i) {
    ll period = d[i];

    while (!events.empty() && get<0>(events.top()) <= period) {
      event cur_event = events.top();
      events.pop();

      int in_or_erase = get<1>(cur_event);
      ll cur_pos = get<2>(cur_event);

      if (in_or_erase == 1) {
        pos_set.insert(cur_pos);
      } else {
        pos_set.erase(cur_pos);
      }
    }

    if (pos_set.empty()) {
      ans[i] = -1LL;
    } else {
      ans[i] = *(pos_set.begin());
    }
  }

  for (auto &e : ans) {
    printf("%lld\n", e.second);
  }

  return 0;
}
